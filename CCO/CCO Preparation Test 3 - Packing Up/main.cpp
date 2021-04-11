#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
const ll MAXN = 2e6+1;
using namespace std;
// convex hull tricks 1,
ll dp[MAXN], pfsum[MAXN];

struct line{
    ll m,b;
    ll getValue(ll x){
        return m*x + b;
    }
    long double inter(line l1){
        ll one = l1.b-b;
        ll two  = m - l1.m;
        return  (long double)one / (long double) two;
    }
};
int main()
{
    dp[0]=0;
    vector<ll>hull;
    ll n,l; scan(n); scan(l);
    ll start = 0;
    for(int i = 1; i <= n; ++i){
        ll a; scan(a);
        pfsum[i]=pfsum[i-1]+a;
    }
    // dp[i] = min0-i(dp[j]......+c)
    // m = -2p[k]
    // z = p[i]+p[i]^2
    //p = dp[j]+p[k]^2+l^2-2lp(k)
    hull.push_back(0);
    for(int i = 1; i <= n; ++i){
        dp[i]=0;
        while(start <= (ll) hull.size() - 2) {
            ll a = hull[start];
            ll b = hull[start+1];
            line temp1 = {(-2 * pfsum[a] - 2*a - 2*l - 2),dp[a]+(pfsum[a]+a+l+1)*(pfsum[a]+a+l+1)};
            line temp2 = {(-2 * pfsum[b] - 2*b - 2*l - 2),dp[b]+(pfsum[b]+b+l+1)*(pfsum[b]+b+l+1)};
            long double inter1 = temp1.inter(temp2);
            if(inter1<(long double)(pfsum[i]+i)) {
                ++start;
            }
            else {
                break;
            }
        }
        ll temp1 = hull[start];
        dp[i]=dp[temp1]+ (pfsum[i]-pfsum[temp1]+ i-temp1-l-1)*(pfsum[i]-pfsum[temp1]+ i-temp1-l-1);
        line new1{(-2 * pfsum[i] - 2*i - 2*l - 2),dp[i]+(pfsum[i]+i+l+1)*(pfsum[i]+i+l+1)};
        while(start <= (ll) hull.size() - 2) {
            ll a = hull[hull.size()-2];
            ll b = hull[hull.size()-1];
            line temp1 = {(-2 * pfsum[a] - 2*a - 2*l - 2),dp[a]+(pfsum[a]+a+l+1)*(pfsum[a]+a+l+1)};
            line temp2 = {(-2 * pfsum[b] - 2*b - 2*l - 2),dp[b]+(pfsum[b]+b+l+1)*(pfsum[b]+b+l+1)};
            long double inter1 = temp1.inter(temp2);
            long double inter2 = temp1.inter(new1);
            if(inter1>inter2){
                hull.pop_back();
            }
            else{
                break;
            }
        }
        hull.push_back(i);

    }
    cout<<dp[n]<<endl;
    return 0;
}
