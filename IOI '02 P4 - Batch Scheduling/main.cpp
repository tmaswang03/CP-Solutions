#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
const ll MAXN = 1e4+1;
using namespace std;
// convex hull tricks 1,
ll dp[MAXN], pfsum[MAXN], pfsum1[MAXN],n,c,start=0,arr[MAXN],arr1[MAXN],a,b;

long double gett(ll a, ll b){
    return (long double)(dp[a]-dp[b])/(long double)(pfsum[a]-pfsum[b]);
}


//x=ax2+bx+c,
int main()
{
    vector<ll>hull;
    scan(n); scan(c);
    for(int i = 0; i < n; ++i){
        scan(arr[i]); scan(arr1[i]);
    }
    for(int i = n-1; i >= 0; --i){
        pfsum[i]=pfsum[i+1]+arr[i];
        pfsum1[i]=pfsum1[i+1]+arr1[i];
    }

    // dp[i] = min0-i(dp[j]+(pfsum[i]-pfsum[j]+c)*(pfsum1[i]-pfsum1[j]))
    hull.push_back(n);
    for(int i = n-1; i >= 0; --i){
        while(start <= (ll) hull.size() - 2) {
            ll line1 = hull[start], line2 = hull[start+1];
            if(gett(line1,line2) <= (long double)pfsum1[i]) ++start;
            else break;
        }
        dp[i]= dp[hull[start]] + (pfsum[i]-pfsum[hull[start]]+c)*(pfsum1[i]);
        while(start <= (ll) hull.size() - 2) {
            if(gett(hull[hull.size()-2],hull[hull.size()-1])>=gett(hull[hull.size()-1],i)) hull.pop_back();
            else break;
        }
        hull.push_back(i);

    }
    cout<<dp[0]<<endl;
    return 0;
}
