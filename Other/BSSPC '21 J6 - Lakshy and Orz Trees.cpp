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
ll N, x, y, a[MM], sz[MM], tot = 0, st[MM]; vector<int> v[MM];
void dfs1(int cur, int par){
    ll sum = 0, sub = 0, ma = 2, top = 0;
    if(cur==1) ma = 3;
    for(auto && i : v[cur]){
        if(i == par) continue;
        dfs1(i, cur);
        sum += sz[i]+a[i];
    }
    for(auto && i : v[cur]){
        if(i==par) continue;
        st[top++] = sz[i] + a[i];
    }
    sort(st, st+top, greater<ll>());
    for(int i = 0; i < min(ma, top); ++i) sub += st[i];
    tot += sum - sub;
    sz[cur] = sub;
}

int main()
{
    boost(); 
    // all nodes must have 2 subtrees, except root 1
    // dp find weight of subtree, if > 2 subtree remove the 2 least costly
    cin>>N;
    for(int i = 2; i <= N; ++i) cin>>a[i];
    for(int i = 1; i < N; ++i){
        cin>>x>>y; v[x].pb(y); v[y].pb(x);
    }
    dfs1(1, -1);
    cout<<tot<<endl;
    return 0;
}