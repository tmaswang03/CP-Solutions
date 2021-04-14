#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 22;
using namespace std;
vector<int> v[MM]; unordered_set<int>st;
int K, N, a, b, sa, sb, cnt = 0;
bool vis[MM], inq[MM];
void dfs(int cur, int src){
    vis[cur] = 1;
    for(auto && i : v[cur]){
        if(i==src){ inq[cur] = 1; st.insert(cur); return;}
        if(vis[i]){continue;}
        dfs(i, src);
        if(inq[i]){
            st.insert(cur); inq[cur] = 1;
        }
    }
    vis[cur] = 0;
}
int main()
{
    cin>>N>>K;
    for(int i = 0; i < K; ++i){
        cin>>a>>b>>sa>>sb;
        if(sa>sb) v[a].pb(b);
        else v[b].pb(a);
    }
    for(int i = 1; i <= N; ++i){ms(vis, 0); ms(inq, 0);  dfs(i, i);}
    cout<<st.size()<<endl;
    return 0;
}