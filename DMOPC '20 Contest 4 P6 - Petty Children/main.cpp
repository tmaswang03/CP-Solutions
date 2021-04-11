#include<bits/stdc++.h>
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
const ll MM = 30;
using namespace std;
int N, M, a, b, res, out[MM], x[MM]; vector<int> v[MM];
void gett(){
    int ret = 0;
    for(int i = 0; i < N; ++i){
        int cnt = 0;
        for(auto && j : v[i]){
            if(x[j]==x[i]) ++cnt;
        }
        if(cnt%2==0) ++ret;
    }
    if(res<ret){
        res = ret;
        for(int i = 0; i < N; ++i) out[i] = x[i];
    }
}
void dfs(int pos){
    if(pos==N){
        gett();
        return;
    }
    x[pos] = 1; dfs(pos+1); x[pos] = 2; dfs(pos+1);
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; ++i){
        cin>>a>>b; --a; --b; v[a].pb(b); v[b].pb(a);
    }
    dfs(0);
    cout<<res<<endl;
    for(int i = 0; i < N-1; ++i) cout<<out[i]<<" ";
    cout<<out[N-1]<<endl;
    return 0;
}
