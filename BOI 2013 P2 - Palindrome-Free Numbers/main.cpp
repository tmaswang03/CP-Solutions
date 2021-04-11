#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
string s1,s2;ull dp[30][11][11][2][2][2];
// find the total number of palindrome free numbers in range 0-b;
// subtract total number of palindrome free numbers in range 0-a; q1-qa = res;
// dp[position][number[pos-2]][number[pos-1]][limit][leading zero];
ull fun (string s, int pos, int prev2, int prev1, bool lmt, bool zero, bool prevzero){
    ull &ret = dp[pos][prev2][prev1][lmt][zero][prevzero];
    if(ret != -1) return ret;
    if(pos >= s.size()){ return dp[pos][prev2][prev1][lmt][zero][prevzero] = 1;}
    int v = s[pos] - '0', bound = lmt? v : 9; ret = 0;
    for(int i = 0; i <= bound; ++i){
        if((!zero && i==prev1)||(i==prev2 && !prevzero)) continue;
        ret += fun(s, pos+1, prev1, i , lmt && i == v, zero && i == 0, zero);
    }
    return dp[pos][prev2][prev1][lmt][zero][prevzero] = ret;
}
int main()
{
    ull a,b; cin>>s1>>s2; ms(dp, -1);
    bool ispal = true;
    ull temp1 = fun(s1,0, 10, 10, 1, 1, 1); ms(dp,-1);
    ull temp2 = fun(s2,0, 10, 10, 1, 1, 1);
    for(int i = 1; i < s1.size(); ++i){
        if(s1[i]==s1[i-1]) ispal = 0;
        if(i>1 && s1[i]==s1[i-2]) ispal = 0;
    }
    cout<<temp2-temp1 + ispal<<endl;
    return 0;
}
