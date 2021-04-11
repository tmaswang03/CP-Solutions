#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
const ll MAXN = 1e6+1;
using namespace std;
// convex hull tricks 1,
ll dp[MAXN], arr[MAXN], pfsum[MAXN],a,b,c;

long double gett(ll j, ll k){
    return (1.0* (dp[j]-dp[k] - a*(arr[j-1]* arr[j-1] -arr[k-1]*arr[k-1]) - b*(arr[j-1] - arr[k-1]))) / (2.0*(arr[j-1] - arr[k-1]) );
 }
//x=ax2+bx+c,
int main()
{
    pfsum[0]=0;
    ms(dp,0);
    vector<ll> hull;
    ll N; scan(N);
    cin>>a>>b>>c;
    ll start = 0;
    for(int i = 1; i <= N; ++i){
        ll a; scan(a);
        arr[i]=a;
        pfsum[i]=pfsum[i-1]+a;
    }
    //x=ax2+bx+c,
    // dp[i] = max0-i(dp[n]+a*getsum(n+1,i)^2+b*getsum(n+1,i)+c)
    //
    for(int i = 1; i <= N; ++i){
        dp[i]=a*pfsum[i]*pfsum[i]+b*pfsum[i]+c;
        while(start <= (ll) hull.size() - 2) {
            ll line1 = hull[start], line2 = hull[start+1];
            if(gett(line1, line2) > pfsum[i]) ++start;
            else break;
        }
        if(i>1){
            ll temp = hull[start];
            dp[i]=max(dp[i],dp[temp] + a*(pfsum[i]-pfsum[temp-1])*(pfsum[i]-pfsum[temp-1]) + c +b*(pfsum[i]-pfsum[temp-1]));
        }
        // i = end, dp[i] = begin
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[hull.size()-2], B = hull[hull.size()-1];
            if(gett(A,B)<=gett(B,i)){
                hull.pop_back();
            }
            else{
                break;
            }
        }
        hull.push_back(i);
    }
    cout<<dp[N]<<endl;

    return 0;
}
