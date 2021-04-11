#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10, seed = 131, seed1 = 31, mod = 1e9+9, mod1 = 1e9+7;
using namespace std;
ll hsh[MM], hsh1[MM], p[MM], p1[MM], L;
unordered_set<ll> ust;
string s;
ll get1 (int l, int len){return ((hsh[l+len-1]-hsh[l-1]*p[len])%mod+mod)%mod;}
ll get2 (int l, int len){return ((hsh1[l+len-1]-hsh1[l-1]*p1[len])%mod1+mod1)%mod1;}
int main()
{
    boost();
    cin>>L>>s;
    p[0] = p1[0] = 1;
    for(int i = 1; i <= s.length(); ++i){
        hsh[i]= (hsh[i-1]*seed+s[i-1])%mod;
        p[i] = (p[i-1]*seed)%mod;
        hsh1[i]= (hsh1[i-1]*seed1+s[i-1])%mod1;
        p1[i] = (p1[i-1]*seed1)%mod1;
    }
    int lo = 0, hi = L, len, res = 0;
    while(hi>=lo){
        ust.clear();
        bool contain = 0;
        len = (lo+hi)/2;
        for(int i = 1; i <= L-len+1; ++i){
            ll hshe = get1(i, len), hshe1 = get2(i, len);
            hshe = (hshe<<32)|hshe1;
            auto it = ust.find(hshe);
            if(it!=ust.end() ){
                res = len;
                contain = 1;
                break;
            }
            ust.insert(hshe);
        }
        if(contain) lo = len+1;
        else hi = len-1;
    }
    cout<<res<<endl;
    return 0;
}
