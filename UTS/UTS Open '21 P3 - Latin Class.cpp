#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10, mod = 1e9+7;
using namespace std;
ll h[MM], N, prefm[MM], res = 1, dp[MM], last = 1, psa[MM];
int main()
{
    cin>>N; dp[1] = psa[1] = 1;
    for(int i = 1; i <= N; ++i) cin>>h[i];
    for(int i = 1; i <= N; ++i){
        prefm[i] =  max(h[i], prefm[i-1]);
    }
    for(int i = 2; i <= N; ++i){
        if(prefm[i]==h[i]) dp[i] = (2*dp[i-1]+psa[i-1]-psa[last])%mod;
        else dp[i] = dp[i-1];
        psa[i] = psa[i-1]+dp[i];
        if(prefm[i]==h[i]) last = i;
    }
    cout<<dp[N]<<endl;
    return 0;
}
