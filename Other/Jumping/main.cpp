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
using namespace std;
const ll MAXN = 2e3+1;
const ll INF = 0x3f3f3f;
bool arr[MAXN][MAXN]; int dp[MAXN][MAXN];
// dp states = the least amount of points to reach the x, yth rock
// dp[h], dp[y]
// dp[k] = dp[y]+(y-k)^2
// dp[k] = dp[x] + (x-k)^2
// dp[y] + (y-k)^2 < dp[x] + (x-k)^2
// dp[y] - dp[x] + y^2 - x^2 < 2xk - 2yk
// dp[y] - dp[x] + y^2 - x^2 < 2(x-y)*k
// (dp[y] - dp[x] + y^2 - x^2) / 2(x-y) < k
// idea : multiple cht
//
long double gett(int j, int k){return (1.0*(dp[j]-dp[k]+j*j-k*k))/(2.0*(j-k));}

int main()
{
    int N, C; scan(N); scan(C);
    for(int c = 0; c < C; ++c){
        for(int r = 0; r < N; ++r){
            char f; cin>>f;
            arr[c][r]=(int)(f-'0'); //row, column
        }
    }
    for(int i = 0; i < C; ++c){
        if(arr[i][0] == 1) dp[i][0]= 0;
        else dp[i][0]= INF;
    }


    return 0;
}
