#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const ll mod = 1e9+7;
using namespace std;
ll a[3], T, K;
ll binpow (ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1LL) res = res*b;
        b*=b; b%=mod; res%=mod;
        e>>=1;
    }
    return res%mod;
}
bool check(){
    if(a[2]-a[1]==a[1]-a[0]) return 1;
    return 0;
}
int main()
{
    cin>>T;
    while(T--){
        for(int i = 0; i < 3; ++i) cin>>a[i];
        cin>>K;
        if(check()){
            cout<<(a[0]+(K-1)*(a[1]-a[0])%mod)%mod<<endl;
        }
        else{
            cout<<(a[0]*binpow(a[1]/a[0], K-1))%mod<<endl;
        }
    }
    return 0;
}
