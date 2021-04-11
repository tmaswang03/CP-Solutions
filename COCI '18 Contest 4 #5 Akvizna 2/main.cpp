#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5+20;
using namespace std;
// dp[i] = max (0-i) (dp[j] + (i-j)/(n-j));
// dp[i] holds the best outcome if you were to have a split at the i'th person
// assuming j>=k
// dp[j] + (i-j)/(n-j) >= dp[k] + (i-k)/(n-k)
// dp[j]-dp[k] + (i-j)/(n-j) - (i-k)/(n-k) >= 0
// dp[j] - dp[k] + ( (i-j)(n-k) - (i-k)(n-k) )/(n-k)(n-j) >= 0
// dp[j] - dp[k] + (i(j-k)- n(j-k) )/ (n-j)(n-k) >= 0
// dp[j] - dp[k] - n(j-k)/(n-j)(n-k) >= i* (k-j)/(n-k)(n-j)
pair<ld, ll> dp[MAXN]; ll n;

ld gett(ll j, ll k){
    return (ld)((dp[j].f-dp[k].s - (ld)(j)/((ld)(n-j))) + (ld)(k)/(ld)(n-k))/((ld)(1.0/((ld)(n-k)) - 1.0/((ld)(n-j))));
}

pair<ld, ll> solve(ld c){
    for(int i = 0; i <= n; ++i) dp[i] = {0,0};
    vector<ll>hull; hull.pb(0); ll start = 0;
    for(int i = 1; i <= n; ++i){
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[start], B = hull[start+1];
            if(gett(A,B) < i) ++start;
            else break;
        }
        ll temp1 = hull[start];
        dp[i].f= dp[temp1].f + (ld)(i-temp1)/(n-temp1)-c;
        dp[i].s = dp[temp1].s + 1;
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[hull.size()-2], B = hull[hull.size()-1];
            if(gett(A,B)<=gett(B,i)) hull.pop_back();
            else break;
        }
        hull.pb(i);
    }
    return dp[n];
}

int main()
{
    int K; scan(n); scan(K);
    ld lo = 0.0, hi = 100000;
    while((ld)abs(lo-hi)>0.001){
        ld mid = (lo+hi)/2.0;
        cout<<mid<<endl;
        pair<ld, int> res = solve(mid);
        cout<<res.f<<" "<<res.s<<endl;
        if(res.s < K){
            lo = mid+0.01;
        }
        else if (res.s > K){
            hi = mid-0.01;
        }
        else{
            cout<<setprecision(9)<<res.f<<endl;
            break;
        }
    }
    return 0;
}
