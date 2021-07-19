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

ll getsum(ll L, ll R){
    ll temp = pfsum[R+1]-pfsum[L];
    return temp;
}

struct line{
    ll m,b;
    ll getValue(ll x){
        return m*x + b;
    }
    long double inter(line l1){
        ll one = l1.b-b;
        ll two  = m - l1.m;
        return  (long double)one / (long double)two;
    }
};
//x=ax2+bx+c,
int main()
{
    pfsum[0]=0;
    ms(dp,0);
    vector<line> hull;
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
            line line1 = hull[start];
            line line2 = hull[start+1];
            if(line1.getValue(pfsum[i]) < line2.getValue(pfsum[i])) {
                ++start;
            }
            else {
                break;
            }
        }
        if(i>1){
            dp[i]=max(dp[i],hull[start].getValue(pfsum[i]) + a*pfsum[i]*pfsum[i] + c +b*pfsum[i]);
        }
        // i = end, dp[i] = begin
        line new1{-2 * a * pfsum[i], dp[i]+a*pfsum[i]*pfsum[i]-b*pfsum[i]};
        while(start <= (ll) hull.size() - 2) {
            line A = hull[hull.size()-2];
            line B = hull[hull.size()-1];
            long double inter1 = A.inter(B); // b.b-b.a / a.m-b.m
            long double inter2 = B.inter(new1); //n.b-b.b / b.m
            if(inter2<inter1){
                hull.pop_back();

            }
            else{
                break;
            }
        }
        hull.push_back(new1);
    }
//    for(int i = 0; i <= N; ++i){
//        cout<<dp[i]<<endl;
//    }
    cout<<dp[N]<<endl;

    return 0;
}