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
ll temp, dp[15][15][2][2]; string s, k;
// dp holds position, previous num,  lmt, zero;
ll solve (string s, ll pos,ll prev,  bool lmt, bool zero){
    ll ret = dp[pos][prev][lmt][zero];
    if (ret!= -1) return ret;
    if(pos == s.size()) return 1;
    int v = s[pos] - '0', bound = lmt? v : 9; ret = 0;
    for(int i = 0; i <= bound; ++i){
        if((abs(prev-i)>=2)||zero)
            ret += solve(s, pos+1, i, lmt && i == v, zero && i == 0);
    }
    return dp[pos][prev][lmt][zero] = ret;
}
int main()
{
    ms(dp, -1);
    cin>>s>>k;
    ll temp1 = solve(s,0,15, 1, 1);
    ms(dp, -1);
    bool istrue = 1;
    ll temp2 = solve(k, 0, 15,1, 1);
    for(int i = 1; i < s.length(); ++i){
        if(abs(s[i]-s[i-1])<2){
            istrue = 0; break;
        }
    }
    cout<<temp2-temp1+istrue<<endl;
    return 0;
}
