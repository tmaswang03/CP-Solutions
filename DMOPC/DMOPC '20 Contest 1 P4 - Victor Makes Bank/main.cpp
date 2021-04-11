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
#define REP(i, n) for(int i = 0; i < n; ++i)
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
using namespace std;
ll N, K, T, C, ans;
// number of days (power), K number of new per month (first multiplier),
// T = time to mature (rows/columns), C = number to start with
struct mat{
    int r, c;
    vector<vector<ll> > m;
    void init(){ m.resize(r, vector<ll>(c));}
    mat operator *(mat& o){
        vector<vector<ll> > res; res.resize(r, vector<ll>(o.c));
        REP(i, r) REP(j, c) REP(k, o.c){ res[i][k]+=m[i][j]*o.m[j][k]; res[i][k]%=MOD; }
        return {r, o.c, res};
    }
};

mat pow(mat a, ll e){
    mat res = {a.r, a.c}; res.init();
    REP(i, a.r) res.m[i][i] = 1;
    while(e){
        if(e&1LL) res= res*a;
        a=a*a;
        e>>=1;
    }
    return res;
}
int main()
{
    cin>>N>>K>>T>>C;
    mat b{T+1, 1}, e{T+1, T+1}; b.init(); e.init();
    REP(i, T) b.m[i][0] = 0;
    b.m[T][0] = 1;
    e.m[0][T] = K;
    for(int i = 1; i <= T; ++i) e.m[i][i-1] = 1;
    e.m[T][T] = 1;
    e = pow(e, N-1);
    b = e*b;
    REP(i, T){
        ans+=C*b.m[i][0]; ans%=MOD;
    }
    ans+=(2*C)%MOD*b.m[T][0]; ans%=MOD;
    cout<<ans<<endl;
    return 0;
}
