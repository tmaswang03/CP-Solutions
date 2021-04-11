#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10, seed = 131;
using namespace std;
string t, s;
ll hsh1[MM], needle = 0, p[MM], res = 0;
ll gethsh(int l, int r){return hsh1[r] - hsh1[l-1]*p[r-l+1];}
int main()
{
    boost();
    cin>>t>>s; p[0] = 1;
    for(int i = 1; i <= t.length(); ++i){
        hsh1[i] = hsh1[i-1]*seed + t[i-1];
        p[i] = p[i-1]*seed;
    }
    for(int i = 1; i <= s.length(); ++i){
        needle  = needle*seed + s[i-1];
    }
    for(int i = 1; i <= t.length()-s.length()+1; ++i){
        if(gethsh(i, i+s.length()-1)==needle) ++res;
    }
    cout<<res<<endl;
    return 0;
}
