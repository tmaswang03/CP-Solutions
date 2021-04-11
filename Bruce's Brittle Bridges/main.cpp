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
const ll MM = 2e5+10;
using namespace std;
int N, va, t, x, y, a[MM], dsu[MM], hed[MM], sz[MM]; vector<pii> v[MM];
// it only matters if the edge is of weight 1 or 2 ??
// if it's weight 2 you can traverse to and back
// optimal traversal only needs to traverse an edge at most 2 times
// to and back
// if there is edge of weight 1 you have 2 options
// 1 : traverse everything underneath the weight 1 and that's the max
// 2 :
int get_head(int h){
    if(hed[h]==h) return h;
    return hed[h] = get_head(ged[h]);
}
int join(int i, int j){
    if(sz[i]< sz[j]) swap(i, j);
    sz[i]+=sz[j]; hed[j] = hed[i];
}
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 0; i < N-1; ++i){
        cin>>x>>y>>t;
        if(t>=2) t = 2;
        v[x].pb({y, t});
        v[y].pb({x, y});

    }
    return 0;
}
