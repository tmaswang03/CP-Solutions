#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;
using namespace std;

int dp[55001];

int main()
{
    ms(dp,0x3f3f3f);
    dp[0]=0;
    int N,M; cin>>N>>M;
    int maxv = 0;
    for(int i =0 ; i < N; ++i){
        int v,w; cin>>v>>w;
        maxv=max(maxv,v);
        for(int i = v; i < M+v; ++i){
            dp[i]=min(dp[i],dp[i-v]+w);
        }
    }
    int min1 = 0x3f3f3f;
    for(int i = M; i <= M+maxv; ++i){
        min1 = min(min1,dp[i]);
    }
    cout<<min1<<endl;
    return 0;
}
