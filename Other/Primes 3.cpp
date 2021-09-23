#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef unsigned long long ll;
using namespace std;

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
    ll T, X; cin>>T;
    while(T--){
        cin>>X;
        if(MillerRabin(X)) cout<<"PRIME"<<endl;
        else cout<<"NOT"<<endl;
    }
    return 0;
}