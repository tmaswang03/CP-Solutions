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
const ll mod = 1e9+7;
using namespace std;
char _;
// pos, yes or no 10, limit, leading zeros;
int dp[100010][2][2][2]; string s;
int fun (int pos, bool haszero, bool hasone, bool lmt){
    int ret = dp[pos][haszero][hasone][lmt];
    if (ret!= -1) return ret;
    if(pos == s.size()) return hasone&&haszero;
    int v = s[pos] - '0', bound = lmt? v : 9; ret = 0;
    for(int i = haszero; i <= bound; ++i){
        if(i==1){ ret += fun(pos+1,haszero, 1, lmt && i == v); ret%=mod;}
        else if(hasone && !i){ ret += fun(pos+1, 1, hasone , lmt && i == v); ret%=mod; }
        else{ ret += fun(pos+1, haszero, hasone, lmt && i == v); ret%=mod;}
    }
    return dp[pos][haszero][hasone][lmt] = ret;
}

int main()
{
    cin>>s; ms(dp, -1);
    cout<<fun(0, 0, 0, 1);
    return 0;
}
