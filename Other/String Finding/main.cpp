#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll seed = 31, MM = 1e6+10, mod = 1e9+7;
using namespace std;
string t, s;
ll hsh[MM], p[MM], f;
ll get(int l, int r){return ((hsh[r]-hsh[l-1]*p[r-l+1])%mod+mod)%mod;}
int main()
{
    cin>>t>>s; p[0] = 1; hsh[0] = 0;
    for(int i = 1; i <= t.length(); ++i){
        hsh[i] = (((hsh[i-1]*seed+t[i-1])%mod)+mod)%mod;
        p[i] = ((p[i-1]*seed%mod)+mod)%mod;
    }
    for(int i = 0; i < s.length(); ++i) f = ((f*seed+s[i])%mod+mod)%mod;
    for(int i = 1; i <= t.length() - s.length()+1; ++i){
        if(f==get(i, i+s.length()-1)){cout<<i-1<<endl; return 0;}
    }
    cout<<-1<<endl;
    return 0;
}
