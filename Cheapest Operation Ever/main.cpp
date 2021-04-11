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
ll dp[MAXN], arr[MAXN];

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


long double gett(int j, int k){
    return (long double )(dp[j-1]-dp[k-1]+arr[j]*arr[j]-arr[k]*arr[k])/(long double )(2*arr[j]-2*arr[k]);
}
//x=ax2+bx+c,
int main()
{
    dp[0]=0;
    vector<ll>hull;
    ll n,c; scan(n); scan(c);
    ll start = 0;
    for(int i = 1; i <= n; ++i){
        ll a; scan(a);
        arr[i]=a;
    }
    // dp[i] = min0-i(dp[j]+(arr[j]-arr[i])^2+H)
    hull.push_back(0);
    dp[0]=0;
    for(int i = 1; i <= n; ++i){
        while(start <= (ll) hull.size() - 2) {
            ll line1 = hull[start];
            ll line2 = hull[start+1];
            if(gett(line1,line2) <= (long double)arr[i]) {
                ++start;
            }
            else {
                break;
            }
        }

        dp[i]=min(dp[i-1]+c,dp[hull[start]-1] + (arr[i]-arr[hull[start]])* (arr[i]-arr[hull[start]])+c);
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[hull.size()-2];
            ll B = hull[hull.size()-1];
            if(gett(A,B)>=gett(B,i)){
                hull.pop_back();
            }
            else{
                break;
            }
        }
        hull.push_back(i);
    }
//    for(int i = 0; i <= n; ++i){
//        cout<<dp[i]<<endl;
//    }
    cout<<dp[n]<<endl;
    return 0;
}
