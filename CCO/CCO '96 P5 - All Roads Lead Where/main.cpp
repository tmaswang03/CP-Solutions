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
const ll MM = 30;
using namespace std;
vector<int> v[MM]; int N, M, par[MM], dst[MM], cur; string c1, c2, out;
int ci (char c){ return (int)(c-'A');}
char ic (int c) { return (char)(c+'A');}
void dfs(int cur, int lvl){
    dst[cur] = lvl;
    for(auto && i : v[cur]){
        if(i==par[cur]) continue;
        if(lvl+1 < dst[i]){
            par[i] = cur;
            dfs(i, lvl+1);
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i  = 0; i < N; ++i){
        cin>>c1>>c2;
        v[ci(c1[0])].pb(ci(c2[0]));
        v[ci(c2[0])].pb(ci(c1[0]));
    }
    while(M--){
        cin>>c1>>c2;
        ms(par, -1); ms(dst, 0x3f); out.clear();
        dfs(ci(c1[0]), 0); cur = ci(c2[0]);
        while(cur!=-1){
            out+=ic(cur);
            cur = par[cur];
        }
        reverse(out.begin(), out.end());
        cout<<out<<endl;
    }
    return 0;
}
