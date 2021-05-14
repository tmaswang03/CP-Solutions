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
const ll MM = 1e5+10;
using namespace std;
int N, l, r, v, t[20][MM], dpth[MM], val[MM], id[MM], Q;
struct seg{
    int l, r, v;
} a[MM];
vector<seg> sweep; vector<int> adj[MM]; stack<int> st;
int lg2(int n){ return 31 - __builtin_clz(n);}
void dfs(int cur, int best){
    if(val[cur]<=val[best]) best = cur;
    id[cur] = best;
    for(auto && i : adj[cur]){
        t[0][i] = cur; dpth[i]=dpth[cur]+1;
        dfs(i, best);
    }
}
void init(){
    for(int l = 1; l < 20; ++l){
        for(int i = 1; i <= N; ++i){
            if(t[l-1][i]!=-1) t[l][i] = t[l-1][t[l-1][i]];
        }
    }
}
int gett(int x, int y){
    if(dpth[x]<dpth[y]) swap(x, y);
    while(dpth[x]!=dpth[y]){
      if(t[lg2(dpth[x]-dpth[y])][x]!=-1) x = t[lg2(dpth[x]-dpth[y])][x];
    }
    if(x==y) return t[0][x];
    for(int i = 19; i >= 0; --i){
        if(t[i][x]!=-1 && t[i][y]!=-1 && t[i][x]!=t[i][y]) x = t[i][x], y = t[i][y];
    }
    return t[0][x];
}
bool cmp(seg &x, seg &y){
    return x.l < y.l;
}
int main()
{
    cin>>N; val[0] = 1e9+10; ms(t, -1);
    for(int i = 1; i <= N; ++i){
        cin>>a[i].l>>a[i].r>>a[i].v; val[i] = a[i].v;
        sweep.pb({a[i].l, 0, i}); sweep.pb({a[i].r, 1, i});
    }
    st.push(0);
    sort(sweep.begin(), sweep.end(), cmp);
    for(int i = 0; i < sweep.size(); ++i){
        if(sweep[i].r==0){
            adj[st.top()].pb(sweep[i].v); st.push(sweep[i].v);
        }
        else st.pop();
    }
    cin>>Q;
    dfs(0, 0); init();
    while(Q--){
        cin>>l>>r;
        int res = gett(l, r);
        if(res==0) cout<<-1<<endl;
        else cout<<id[res]<<endl;
    }
    return 0;
}
