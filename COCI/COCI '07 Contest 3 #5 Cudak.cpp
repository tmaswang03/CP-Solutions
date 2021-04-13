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
ll sum, counter = 0, num1, num2, dp[20][200][2]; string s, k;
// dp holds position, previous num,  lmt, zero;
ll solve (string s, ll pos,ll prev,  bool lmt){
    ll ret = dp[pos][prev][lmt];
    if (ret!= -1) return ret;
    if(pos == s.size()) return dp[pos][prev][lmt] = (prev==sum);
    if(prev>sum) return dp[pos][prev][lmt] = 0;
    int v = s[pos] - '0', bound = lmt? v : 9; ret = 0;
    for(int i = 0; i <= bound; ++i){
        ret += solve(s, pos+1, i+prev, lmt && i == v);
    }
    return dp[pos][prev][lmt] = ret;
}

ll bs(ll i){
    string s = to_string(i);
    ms(dp, -1);
    return solve(s, 0, 0, 1);
}

int main()
{
    ms(dp, -1);
    cin>>num1>>num2>>sum;
    s = to_string(num1); k = to_string(num2);
    ll temp1 = solve(s,0,0, 1), copy1 = num1-1, res;
    ms(dp, -1);
    ll temp2 = solve(k, 0, 0,1);
    for(int i = 0; i < s.length(); ++i){
        counter+=s[i]-'0';
    }
    cout<<temp2-temp1+(counter==sum)<<endl;
    counter=0;
    while(num2 >= num1){
        ll i = (num1+num2)/2;
        if(bs(i)-bs(copy1)){
            res = i;
            num2 = i-1;
        }
        else{
            num1 = i+1;
        }
    }
    cout<<res<<endl;
    return 0;
}
