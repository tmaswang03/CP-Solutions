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
const ll MM = 3e5+10, LOG = 20;
using namespace std;
int N, top[MM], par[MM], dpth[MM], id[MM], b, a, lca[LOG][MM]; char opt;
// idea : keep the top of each stack
// if the option is remove, par[c] = par[[par[c]], depth = depth[par] - 1;
// for query, the answer = the minimum depth between 2 stacks and lcas
int lg2(int n) { return 31 - __builtin_clz(n);}
void init(int cur){
    lca[0][cur] = par[cur];
    for(int i = 1; i < LOG; ++i) lca[i][cur] = lca[i-1][lca[i-1][cur]];
}
int gett(int a, int b){
    if(dpth[a]<dpth[b]) swap(a, b);
    while(dpth[a]!=dpth[b]){a = id[lca[lg2(dpth[a]-dpth[b])][a]]; }
    if(a==b) return a;
    for(int i = LOG-1; i >= 0; --i){
        if(lca[i][a]>0 && lca[i][b]>0 && lca[i][a]!=lca[i][b]) a = lca[i][a], b = lca[i][b];
    }
    return lca[0][a];
}
int main()
{
    boost();
    cin>>N; ms(dpth, 0); ms(lca, 0); ms(id, 0);
    for(int i = 1; i <= N; ++i){
        cin>>opt>>a;
        if(opt == 'a'){
            par[i] = id[a]; dpth[i] = dpth[id[a]]+1; top[i] = i; id[i] = i;
            init(i);
        }
        else if(opt=='b'){
            cout<<top[a]<<endl;
            par[i] = par[id[a]]; top[i] = top[par[i]]; id[i] = id[par[id[a]]];
        }
        else{
            cin>>b;
            par[i] = id[a]; top[i] = top[a]; id[i] = id[a];
            cout<<dpth[gett(id[a], id[b])]<<endl;
        }
    }
    return 0;
}
