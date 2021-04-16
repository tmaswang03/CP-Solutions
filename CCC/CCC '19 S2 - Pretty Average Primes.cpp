#include<bits/stdc++.h>
typedef long long ll;
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
    int T; cin>>T;
    for(int i =0 ; i < T; ++i){
        int N; cin>>N;
        int temp1 = N;
        while(temp1>= 2){
            if(MillerRabin(temp1) && MillerRabin(2*N-temp1)){
                cout<<temp1<<" "<<2*N-temp1<<endl;
                break;;
            }
            --temp1;
        }
    }
    return 0;
}
