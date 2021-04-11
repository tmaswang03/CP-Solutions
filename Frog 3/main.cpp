#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define pb push_back
char _;
typedef long long ll;
const ll MAXN = 2e5+1;
using namespace std;
ll dp[MAXN], arr[MAXN];

__attribute__((hot)) long double gett(int j, int k){
    return (1.0*(dp[j]-dp[k]+arr[j]*arr[j]-arr[k]*arr[k]))/(2.0*(arr[j]-arr[k]));
}
//x=ax2+bx+c,
int main()
{
    vector<int>hull; hull.pb(0);
    ll n,c, start = 0; scan(n); scan(c);
    for(int i = 0; i < n; ++i) scan(arr[i]);
    for(int i = 1; i < n; ++i){
        while(start <= (ll) hull.size() - 2) {
            ll line1 = hull[start], line2 = hull[start+1];
            if(gett(line2,line1) <= (long double)arr[i]) ++start;
            else break;
        }
        dp[i]=dp[hull[start]] + (arr[i]-arr[hull[start]])* (arr[i]-arr[hull[start]])+c;
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[hull.size()-2], B = hull[hull.size()-1];
            if(gett(A,B)>=gett(B,i)) hull.pop_back();
            else break;
        }
        hull.pb(i);
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}
