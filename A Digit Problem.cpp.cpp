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
const int mod = 1e9+7;
using namespace std;
int N, sol, dp[1002][1050][2][2]; string k;

int solve (int pos, int mask, bool lmt, bool zero){
    int ret = dp[pos][mask][lmt][zero];
    if (ret!= -1) return ret;
    if(pos == k.size()){ return ret = (sol & mask) == sol;}
    int cur = k[pos] - '0', upb = 9, nxt = pos+1; ret = 0;
    if(lmt) upb = cur;
    for(int i = 0; i <= upb; ++i){
        if(zero && !i){
            if(lmt && !(i^cur)) ret += solve(nxt, mask, lmt, zero);
            else ret+= solve(nxt, mask, 0, 1);
        }
        else{
            if(lmt && !(i^cur)) ret += solve(nxt, mask|(1<<i), lmt, 0);
            else ret += solve(nxt, mask|(1<<i), 0, 0);
        }
        ret%=mod;
    }
    return dp[pos][mask][lmt][zero] = ret;
}

int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 1; i <= N; ++i){
        int x;
        cin>>x; sol |= 1 << x;
    }
    cin>>k;
    cout<<solve(0, 0, 1, 1) + (sol == 1)<<endl;

    return 0;
}
