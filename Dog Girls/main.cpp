#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 5e3+10, seed = 131, mod = 1e9+9;
using namespace std;
// idea : only possible magical words can be split into integer amount of equal substrings
// pick a length of the string and iterate through all left points of that length
ll hsh[MM], p[MM], res = 0;
bool visited[MM];
string s;
unordered_set<ll>used;
ll gethsh(int l, int r){return ((hsh[r]-hsh[l-1]*p[r-l+1])%mod+mod)%mod;}
int main()
{
    boost();
    cin>>s; p[0] = 1;
    for(int i = 1; i <= s.length(); ++i){
        hsh[i] = (hsh[i-1]*seed+s[i-1])%mod;
        p[i] = (p[i-1]*seed)%mod;
    }
    for(int len = 1; len <= s.length()/2+1; ++len){
        ms(visited, 0);
        for(int l = 1; l <= s.length()+1-len; ++l){
            if(visited[l]) continue;
            ll cur = gethsh(l, l+len-1), cnt = 0;
            for(int lft = l+len; lft <= s.length()+1-len; lft+=len){
                ll newhsh = gethsh(l, lft+len-1), newhsh1 = gethsh(lft, lft+len-1);
                if(newhsh1!=cur) break;
                if(used.find(newhsh)!=used.end()) continue;
                used.insert(newhsh);
                visited[lft] = 1;
            }
        }
    }
    cout<<used.size()<<endl;
    return 0;
}
