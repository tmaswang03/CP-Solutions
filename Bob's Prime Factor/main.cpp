#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;
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
    int N; scan(N);
    int maxp = 0, maxint = 0;
    for(int i = 0; i < N; ++i){
        int a; cin>>a;
        for(int j = a; j > maxp; --j){
            if(a%j==0 && MillerRabin(j)){
                maxp = j;
                maxint = a;
            }
        }

    }
    cout<<maxint<<endl;
    return 0;
}
