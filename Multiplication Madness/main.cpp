#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll MM = 1e6+10, mod = 1e9+7, MN = 1e6;
using namespace std;
ll fac[MM], inv[MM], N, x, y;
ll gett(ll in){
    ll out = 1, e = mod-2;
    while(e){
        if(e&1LL) out*=in;
        in*=in; e>>=1; out%=mod; in%=mod;
    }
    return out%mod;
}
int main()
{
    cin>>N; fac[0] = 1;
    for(int i = 1; i <= MN; ++i){
        fac[i]=(i*fac[i-1])%mod;
    }
    inv[MN] = gett(fac[MN]);
    for(int i = MN-1; i >= 0; --i){
        inv[i] = (inv[i+1]*(i+1))%mod;
    }
    while(N--){
        cin>>x>>y;
        cout<<(fac[y]*inv[x-1])%mod<<endl;
    }
    return 0;
}
