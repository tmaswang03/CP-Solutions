#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
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
int N, Q, t[20][MM], x, k;
int main()
{
    ms(t, -1);
    cin>>N>>Q;
    for(int i = 2; i <= N; ++i) cin>>t[0][i];
    for(int i = 1; i < 20; ++i){
        for(int j = 2; j <= N; ++j){
            t[i][j] = t[i-1][t[i-1][j]];
            if(!t[i][j]) t[i][j] = -1;
        }
    }
    while(Q--){
        cin>>x>>k; int cnt = 0;
        while(cnt!=k){
            int tmp = log2(k-cnt);
            cnt+=(1<<tmp);
            x = t[tmp][x];
        }
        if(x) cout<<x<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
