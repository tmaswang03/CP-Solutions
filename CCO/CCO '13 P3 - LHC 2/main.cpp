#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 4e5+1;
ll diameter = -1, res = 0;
using namespace std;
vector<int>v[MAXN];
ll dp[MAXN], sum[MAXN];
bool visited[MAXN];

void dfs(int node1){
    visited[node1] = 1;
    for(auto && i : v[node1]){ //get longest path and keep track of the values of each path
        if(!visited[i]){
            dfs(i);
            if(dp[i]+dp[node1]>diameter-1){
                diameter = dp[node1] + dp[i] + 1;
                res = sum[node1]*sum[i];
            }
            else if (dp[node1]+dp[i] == diameter-1){
                res+=sum[node1]*sum[i];
            }
            if(dp[node1] < dp[i]+1){
                dp[node1] = dp[i]+1;
                sum[node1] = sum[i];
            }
            else if(dp[node1] == dp[i]+1){
                sum[node1]+=sum[i];
            }
        }

    }

}


int main()
{
    int N; scan(N);
    for(int i = 0; i < N-1; ++i){
        int a,b; scan(a); scan(b);
        v[a].pb(b);
        v[b].pb(a);
        sum[i] = 1;
    }
    sum[N] = sum[N-1] = 1;
    ms(dp, 0);
    ms(visited, 0);
    dfs(1);
    ++diameter;
    cout<<diameter<<" "<<res<<endl;
//    for(int i = 1; i <= N; ++i){
//        cout<<sum[i]<<endl;
//    }
    return 0;
}
