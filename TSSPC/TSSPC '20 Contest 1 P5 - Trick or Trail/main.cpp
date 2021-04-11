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
const ll MOD = 1e9+7, MM = 1e7+10;
using namespace std;
int N, M;
ll powmod(ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1LL) res*=b;
        b*=b; e>>=1; res%=MOD; b%=MOD;
    }
    return res;
}

ll choose(ll a, ll b){
    if(b < a-b) b = a-b;
    ll cur = 1, div = a-b;
    for(a; a > b; --a){
        cur*=a; cur%=MOD;
    }
    for(div; div >= 1; --div){
        cur*=powmod(div, MOD-2);
        cur%=MOD;
    }
    return cur;
}
//
int main()
{
    // how many different ways can you form M up, N across
    // = M+N choose N
    cin>>N>>M;
    if(M+N >= MOD){ cout<<0<<endl; return 0;}
    cout<<choose(M+N, N)<<endl;
    return 0;
}
