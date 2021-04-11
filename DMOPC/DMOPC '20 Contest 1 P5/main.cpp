#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
int N, K, M, a, b, dp[MM], opt, mark[MM]; vector<int> v[MM]; bool vis[MM];
void cover(int cur, int srch, int par){
    if(srch==cur){ vis[cur] = 1; return;}
    for(auto && i : v[cur]){
        if(i==par||vis[i]) continue;
        cover(i, srch, cur);
        if(vis[i]) vis[cur] = 1;
    }
}
int main()
{
    cin>>N>>K>>M; ms(vis, 0); ms(dp, 0);
    for(int i = 1; i <= N; ++i){
        cin>>a; mark[i] = a;
    }
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    }
    for(int i = 1; i <= K; ++i){
        ms(vis, 0);
        for(auto && j : mark[i]){
            cover(1, j, -1);
        }
        for(int j = 1; j <= N; ++j){
            if(vis[j]) ++dp[j];
        }
    }
    for(int i = 0; i < M; ++i){
        cin>>opt>>a;
        if(opt==1) cin>>b;
        else{
            cout<<dp[a]<<endl;
        }
    }
    return 0;
}
