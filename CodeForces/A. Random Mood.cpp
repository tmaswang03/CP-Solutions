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
typedef double ll;
typedef long double ld;
using namespace std;
int N; double P;
struct mat{
    int r, c;
    vector<vector<ll> > m;
    void init(){ m.resize(r, vector<ll>(c));}
    mat operator *(mat& o){
        vector<vector<ll> > res; res.resize(r, vector<ll>(o.c));
        REP(i, r) REP(j, c) REP(k, o.c){ res[i][k]+=m[i][j]*o.m[j][k];; }
        return {r, o.c, res};
    }
};

mat pow(mat a, long long e){
    mat res = {a.r, a.c}; res.init();
    REP(i, a.r) res.m[i][i] = 1;
    while(e){
        if(e&1LL) res = res*a;
        a=a*a;
        e>>=1;
    }
    return res;
}
int main()
{
    cin>>N>>P;
    mat e = {2, 2}; // happy = 1, sad = 0;
    e.m = {{1.0-P, P}, {P, 1.0-P} }; // sad to sad, sad to happy
    e = pow(e, N);
    cout<<fixed<<setprecision(8)<<e.m[1][1]<<endl;
    return 0;
}
