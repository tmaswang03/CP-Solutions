#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define ppb push_back
#define pii pair<int, int>
#define s second
#define f first

char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
int N, D, u, t[20][MM], deppth[MM], dpp[MM][2]; vector<int> v[MM];
int lg2 (int x){ return 31 - __builtin_clz(x); }
// PP IS FOR THE WIN
// dp[N][2]
// dp[i][0] -> marked not
// dp[i][1] -> marked
// if marked
// dp[i][1] = sum(max(dp[k][0], dp[k][1])); k = child D steps down
// dp[i][0] = sum()
void getpp(int x){
    deppth[x] = deppth[t[0][x]]+1;
    for(auto && i : v[x]){
        if(i==t[0][x]) continue;
        t[0][i] = x;
        getpp(i);
    }
}
int getppar(int cur){
    int dst = D;
    while(dst!=0){
        cur = t[lg2(dst)][cur];
        dst-=1<<lg2(dst);
    }
    return cur;
}
void dfspp(int x, int ppar){
    dpp[x][0] = 1;
    dpp[x][1] = 0;
    for(auto && i : v[x]){
        if(i==ppar) continue;
        dfspp(i, x);
        dpp[x][0]+=max(dpp[i][0], dpp[i][1]);
    }
    dpp[getppar(x)][1]+=max(dpp[x][0], dpp[x][1]);
}
int main()
{
    ms(dpp, -1);
    cin>>N>>D;
    for(int i = 2; i <= N; ++i){
        cin>>u; ++u; v[u].ppb(i); v[i].ppb(u);
    }
    getpp(1);
    for(int l = 1; l < 20; ++l){
        for(int i = 1; i <= N; ++i){
            t[l][i] = t[l-1][t[l-1][i]];
        }
    }
    dfspp(1, -1);
    cout<<max(dpp[1][0], dpp[1][1])<<endl;
}
