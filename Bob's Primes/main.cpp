#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef int ll;
using namespace std;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;


ll modulo(__int128_t base, ll e, ll mod) {
    __int128_t result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e /= 2;
    }
    return result;
}

bool prime(ll n, ll a, ll d, ll s) {
    __int128_t x = modulo(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d /= 2;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (prime(n, a, d, s))
            return false;
    }
    return true;
}
int main()
{
    int n,m; scan(n); scan(m);
    bool dp[10000], primetime=false;
    ms(dp,0);
    int arr[100], min1=0;
    for(int i = 0; i < m; ++i){
        int a; scan(a);
        arr[i]=a;
    }
    for(int i = 0 ; i < m; ++i){
        min1+=2*arr[i];
    }
    if(min1>=n){
        printf("not primetime\n");
    }
    else{
        dp[min1]=1;
        for(int i = 0; i < m; ++i){
            for(int j = min1+arr[i]; j<=n; ++j){
                if(dp[j-arr[i]]){
                    dp[j]=1;
                }
            }
        }
        for(int i = min1; i <= n; ++i){
            if(MillerRabin(i) && dp[i]){
                primetime=1;
                break;
            }
        }
        printf(primetime ? "its primetime\n" : "not primetime\n");
    }

    return 0;
}
