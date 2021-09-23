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
const ll MM = 1e6+1, seed = 131, mod = 1e9+7;
using namespace std;
ll hsh1[MM], hsh2[MM], p1[MM];
string str1, str2;
ll modd(ll in){return (in%mod + mod)%mod; }
ll get1(int l, int r){return modd(hsh1[r] - hsh1[l-1]*p1[r-l+1]); }
ll get2(int l, int r){return modd(hsh2[r] - hsh2[l-1]*p1[r-l+1]);}

bool ok(ll pt){
    int nd = str1.length();
    if(get1(pt,nd)==get2(1,nd-pt+1)) return 1;
    return 0;
}

int main()
{
    boost();
    p1[0] = 1; hsh1[0] = hsh2[0] = 0;
    cin>>str1>>str2;
    for(int i = 1; i <= str1.length(); ++i){
        hsh1[i] = modd(hsh1[i-1]*seed+(str1[i-1]-'A'+1));
        p1[i] = modd(p1[i-1]*seed);
    }
    for(int i = 1; i <= str2.length(); ++i){
        hsh2[i] = modd(hsh2[i-1]*seed+(str2[i-1]-'A'+1));
        p1[i] = modd(p1[i-1]*seed);
    }
    ll inter = str1.length()+1;
    for(int i = 1; i <= str1.length(); ++i){
        if(ok(i)){
            inter = i; break;
        }
    }
    cout<<str1.substr(0, inter-1)+str2<<endl;
    return 0;
}