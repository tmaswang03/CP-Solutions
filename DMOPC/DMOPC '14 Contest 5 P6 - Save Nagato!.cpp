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
const ll MM = 5e5+10;
using namespace std;
int N, a, b, up[MM], down[MM], p[MM]; vector<int> v[MM]; queue<pii> q; bool vis[MM];
// find the maximum depth at each node?
// up or down
// down[cur] = max(down[child] + 1)
// up[cur] = max(1 + up[par], all children from parents down[child] + 2);
void dfs1(int cur, int par) {
    down[cur] = 1; p[cur] = par;
    for(auto && i : v[cur]) {
        if(par == i) continue;
        dfs1(i, cur);
        down[cur] = max(down[cur], down[i] + 1);
    }
}

void dfs2(int cur, int par) {
    int m1 = 0, m2 = 0, id1, id2;
    for(auto && i : v[cur]) {
        if(i == par) continue;
        if(down[i] + 2 >= m1) {
            m2 = m1; id2 = id1; m1 = down[i] + 2; id1 = i;
        }
        else if(down[i] + 2 > m2) {
            m2 = down[i] + 2; id2 = i;
        }
    }
    for(auto && i : v[cur]) {
        if(i==par) continue;
        if(i != id1) up[i] = max(up[i], m1);
        else up[i] = max(up[i], m2);
        up[i] = max(up[i], up[cur] + 1);
        dfs2(i, cur);
    }
}
int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N-1; ++i) {
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    }
    dfs1(1, -1); up[1] = 1; dfs2(1, 0);
    for(int i = 1; i <= N; ++i) {
        cout<<max(up[i], down[i])<<endl;
    }
    return 0;
}