#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
const ll MM = 1e6+10, seed = 131;
using namespace std;
string s; char mn = 'z';
ll len, hsh1[MM], p[MM], ret = 1;
ll gethsh(int l, int r){return hsh1[r]-hsh1[l-1]*p[r-l+1];}
int main()
{
    p[0] = 1;
    boost();
    cin>>s>>len;
    for(int i = 1; i <= s.length()+1; ++i){
        hsh1[i] = hsh1[i-1]*seed+s[i-1];
        p[i] = p[i-1]*seed;
        if(i+len>s.length()+1) continue;
         mn = min(mn, s[i-1]);
    }
    for(int i = 1; i+len <= s.length()+1; ++i){
        if(s[i-1]!=mn) continue;
        int lo = i, hi = i+len-1, mid, res = hi;
        while(hi>=lo){
            mid = (hi+lo)>>1;
            if(gethsh(i, mid)==gethsh(ret, ret+mid-i)) lo = mid+1;
            else{
                hi = mid-1; res = mid;
            }
        }
        if(s[res-1] < s[ret+res-i-1]) ret = i;
    }
    cout<<s.substr(ret-1, len)<<endl;
    return 0;
}
