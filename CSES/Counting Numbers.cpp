#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a));
typedef long long ll;
using namespace std;
string a, b; ll dp[20][20][2][2], x, y;
ll solve(string s, int pos, int prev, bool lmt, bool zero){
    ll ret = dp[pos][prev][lmt][zero];
    if(ret!=-1) return ret;
    if(pos==s.size()) return 1;
    int cur = s[pos]-'0', top  = lmt ? cur : 9; ret = 0;
    for(int i = 0; i <= top; ++i){
        if(i==prev && !zero) continue;
        ret+=solve(s, pos+1, i, (i==top)&&lmt, zero && i == 0);
    }
    return dp[pos][prev][lmt][zero] = ret;
}
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>x>>y; ms(dp, -1); a = to_string(x-1), b = to_string(y);
    ll temp1 = solve(b, 0, 10, 1, 1); ms(dp, -1);
    ll temp2 = solve(a, 0, 10, 1, 1);
    cout<<temp1-temp2<<endl;
    return 0;
}
