#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e6+1;
using namespace std;
const ll mod = 1e9+7;
char _;
int T, n, d[20]; ll lo,hi; ll dp[20][2520][1<<8];
ll fun (int pos, int rem, int mask, bool lmt){
    if(!lmt && dp[pos][rem][mask]!=-1) return dp[pos][rem][mask];
    if(pos==0){
        for(int i = 2; i <= 9; i++)
            if (mask & 1 << (i-2) && rem % i != 0) return 0;
        return 1;
    }
    int up = lmt ? d[pos] : 9; ll ret = 0;
    for(int i = 0; i <= up; ++i){
        int nmask = i>=2 ? mask | 1<<(i-2) : mask;
        ret += fun(pos-1, (rem*10+i)%2520, nmask, lmt && i== d[pos]);
    }
    if(!lmt) dp[pos][rem][mask] = ret;
    return ret;
}

ll solve(ll x){
    n = 0;
    for(; x; x/=10) d[++n] = x%10;
    return fun(n, 0, 0, 1);
}

int main()
{
    ms(dp, -1);
    for(cin>>T; T; T-- ){
        cin>>lo>>hi;
        cout<<solve(hi)-solve(lo-1)<<"\n";
    }
    return 0;
}
