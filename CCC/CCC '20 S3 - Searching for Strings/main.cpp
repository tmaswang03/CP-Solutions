#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int MAXN = 2010;
const ll mod = 1e9+7, mod1 = 1e9+9, p1 = 31, p2 = 131;
ll ps[MAXN];
using namespace std;
ll pow(ll base, ll e, ll mod) {
    ll result = 1;
    base%=mod;
    while (e) {
        if (e & 1)
            result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e /= 2;
    }
    return result;
}

using namespace std;
int main()
{
    string p, h; cin>>p>>h;
    int freq1[27], freq2[27];  ms(freq1, 0); ms(freq2, 0);
    set<pair<ll, ll > >used;
    for(int i = 0; i < p.length(); ++i){
        ++freq1[p[i]-'a'];
    }
    ll hash1 = 0, hash2 = 0, po = pow(p1, p.length()-1, mod), po2 = pow(p2, p.length()-1, mod1);
    for(int i = 0; i < p.length(); ++i){
        ++freq2[h[i]-'a'];
        hash1 = (hash1*p1 + (h[i]-'a'+1))%mod;
        hash2 = (hash2*p2 + (h[i]-'a'+1))%mod1;
    }
    bool eq = 1;
    for(int i = 0; i < 26; ++i){
        if(freq1[i]!=freq2[i]){
            eq = 0; break;
        }
    }
    if(eq){
        used.insert(mp(hash1, hash2));
    }
    for(int i = p.length(); i < h.length(); ++i){
        char n = h[i], o = h[i-p.length()];
        eq = 1;
        --freq2[o-'a'];
        ++freq2[n-'a'];
        hash1 = ((hash1 - (o-'a'+1)*po)%mod + mod)%mod;
        hash1 = (hash1*p1 + n-'a'+1)%mod;
        hash2 = ((hash2 - (o-'a'+1)*po2)%mod1 + mod1)%mod1;
        hash2 = (hash2*p2 + n-'a'+1)%mod1;
        for(int i = 0; i < 26; ++i){
            if(freq1[i]!=freq2[i]){
                eq = 0; break;
            }
        }
        if(eq){
            used.insert(mp(hash1, hash2));
        }
    }
    cout<<used.size()<<endl;
    return 0;
}
