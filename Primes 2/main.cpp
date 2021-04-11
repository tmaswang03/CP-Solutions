#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
vector<ll>primes1;

void initsieve(ll s , bool primes[]){ //s = size of sieve
    ll i = 2;
    while(i*i <= s){
        if(primes[i]){
            for(ll j = 2; j < s; ++j){
                if(i*j > s) break;
                else primes[i*j] = 0;
            }
        }
        ++i;
    }
    for(ll k = 2; k <= s; ++k){
        if(primes[k]){
            primes1.pb(k);
        }
    }
}

void initsegsieve(ll high, ll low, bool segsieve[]){ // high = maxval, low = lowval, s = size of sieve
    for(ll i = 0; i < primes1.size(); ++i){
        ll temp = primes1[i];
        ll mins = (low/temp)*temp;
        if(mins < low) mins+=temp;
        if(mins == temp) mins += temp;
        for(ll j = mins; j <= high; j+=temp){
            segsieve[j-low] = 0;
        }
    }
}

int main()
{
    //segmented sieve
    //o(root(m) + m-n) space = 1e5;
    ll n,m; scan(n); scan(m);
    ll r1 = floor(sqrt(m))+1, r2 = m-n+1;
    bool sieve[r1+1], segsieve[r2+1];
    ms(sieve, 1); ms(segsieve,1);
    sieve[0] = sieve[1] =0;
    initsieve(r1, sieve);
    initsegsieve(m,n,segsieve);
    ll counter = 0;
    for(int i = 0; i < r2; ++i){
        if(segsieve[i] && i + n > 1 && i + n < m){
            cout<<i+n<<endl;
        }
    }
    return 0;
}
