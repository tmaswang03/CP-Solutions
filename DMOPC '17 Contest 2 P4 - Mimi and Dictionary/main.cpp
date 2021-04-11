#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll seed = 131, MM = 1e5+10;
using namespace std;
ll hsh[MM], rhsh[MM], p[MM], res = 1;
string s;
ll get1(int r){return hsh[r];}
ll get2 (int r){return rhsh[1]-rhsh[r+1]*p[r];}
ll rolhash (int l, int r){return hsh[r]-hsh[l-1]*p[r-l+1];}

unordered_map<ll,ll> mep;
int main()
{
    boost();
    cin>>s;
    p[0] = 1; hsh[0] = rhsh[s.length()+1] = 0;
    for(int i = 1; i <= s.length(); ++i){
        p[i] = p[i-1]*seed;
        hsh[i] = hsh[i-1]*seed + (s[i-1]-'a'+1);
    }
    for(int i = s.length(); i>= 1; --i){
        rhsh[i] = rhsh[i+1]*seed + (s[i-1]-'a'+1);
    }
    for(int r = s.length(); r >=1; --r){
        if(get1(r)==get2(r)){
            for(int ri = r+1; ri <= s.length(); ++ri){
                if(rolhash(ri-r+1,ri)==get1(r)){
                    cout<<r<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
