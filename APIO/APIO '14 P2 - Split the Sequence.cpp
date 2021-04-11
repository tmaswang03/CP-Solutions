#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef  unsigned long long ull;
typedef long long ll;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f;
using namespace std;
// convex hull tricks 1,
ull dp[MAXN][2], pfsum[MAXN];
int to[MAXN][201], n, c;
// how many splits + the partition point
// dp[i][k]= min 0 - i dp[j][k-1]+pfsum[j]*(pfsum[i]-pfsum[j])
// dp[j][k-1]+pfsum[j]*(pfsum[i]-pfsum[j]) > dp[n][k-1]+pfsum[n]*(pfsum[i]-pfsum[n])
// dp[j][k-1] +pfsum[j]*pfsum[i]-pfsum[j]^2 > dp[n][k-1] +pfsum[n]*pfsum[i]-pfsum[n]^2
// dp[j][k-1] - dp[n][k-1]-pfsum[j]^2 + pfsum[n]^2 > pfsum[n]*pfsum[i] - pfsum[j]*pfsum[i]
// (dp[j][k-1] - dp[n][k-1]-pfsum[j]^2 + pfsum[n]^2 )/(pfsum[n]-pfsum[j]) > pfsum[i]
// don't be retarded you only need to hold 2 states -___-
vector<int>hull, prevhull; int prevstart;

long double gett(int j, int n, int k){
    return (long double )(dp[j][k&1] - dp[n][k&1]-pfsum[j]*pfsum[j]+pfsum[n]*pfsum[n])/(long double )(pfsum[n]-pfsum[j]);
}



int main()
{
    //dp parenthesization + cht(optimization)
    // states =  start, ks left
    // trans = all end pts
    //  splits = spt-sp1 (totsplit - last states splits) (o(n)^2*k)
    scan(n); scan(c);
    for(int i = 1; i <= n; ++i){
        scan(pfsum[i]);
        pfsum[i]+=pfsum[i-1];
    }
    for(int i = 1; i <= n; ++i){
        while(hull.size() >= 2) {
            int A = hull[hull.size()-2]; int B = hull[hull.size()-1];
            if(gett(A,B,0) >= gett(A,i,0)) hull.pop_back();
            else break;

        }
        hull.push_back(i);
    }
    for(int k = 1; k <= c; ++k){
        prevstart = 0;
        prevhull.clear();
        for(int t = 0; t < hull.size(); ++t){
            prevhull.push_back(hull[t]);
        }
        hull.clear();
        for(int i = k+1; i <= n; ++i){
            while(prevstart <= prevhull.size() - 2 ) {
                int line1 = prevhull[prevstart]; int line2 = prevhull[prevstart+1];
                if(line2 < i && (gett(line1,line2, k-1) <= pfsum[i] || isnan(gett(line1,line2,k-1))))++prevstart;
                else break;
            }
            // dp[i][k]= min 0 - i dp[j][k-1]+pfsum[j]*(pfsum[i]-pfsum[j])
            int temp1 = prevhull[prevstart]; to[i][k]=temp1; dp[i][k&1]= dp[temp1][(k-1)&1]+pfsum[temp1]*(pfsum[i]-pfsum[temp1]);
            while(hull.size()>=2) {
                int A = hull[hull.size()-2]; int B = hull[hull.size()-1];
                if(gett(A,B,k)>=gett(A,i,k)) hull.pop_back();
                else break;
            }
            hull.push_back(i);
        }
    }
    cout<<dp[n][c&1]<<endl;
    priority_queue< int, vector<int>,greater<int> >q;
    int cur = n;
    for(int k = c; k >= 0; --k){
        q.push(to[cur][k]);
        cur = to[cur][k];
    }
    q.pop();
    while(!q.empty()){
        ll temp1 = q.top();
        q.pop();
        cout<<temp1<<" ";
    }
    return 0;
}
