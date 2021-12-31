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
const ll MM = 1e4+10;
using namespace std;
vector<int> v[MM]; int N, M, a, b; bool vis[MM], in[MM];
bool dfs(int cur) {
    in[cur] = 1; vis[cur] = 1;
    for(auto && i : v[cur]) {
        if(in[i]) return 0;
        if(vis[i]) continue;
        if(!dfs(i)) return 0;
    }
    in[cur] = 0;
    return 1;
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; ++i) {
        cin>>a>>b; v[a].pb(b);
    }
    for(int i = 1; i <= N; ++i) {
        if(!vis[i] && !dfs(i)) { cout<<"N"<<endl; return 0; }
    }
    cout<<"Y"<<endl;
    return 0;
}