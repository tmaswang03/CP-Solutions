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
const ll MOD = 1e9+7;
using namespace std;
int N, K, res = 0;
struct mat{
    int r, c; vector<vector<int> > m;
    mat(int x, int y){ m.resize(x, vector<int>(y)); r = x; c = y;}
    mat operator *(mat& o){
        mat res {r, o.c};
        REP(i, r) REP(j, c) REP(k, o.c) res.m[i][k]+=m[i][j]*o.m[j][k];
        return res;
    }
};

mat pow(mat a, int e){
    mat res {a.r, a.c};
    REP(i, a.r) res.m[i][i] = 1;
    while(e){
        if(e&1) res= res*a;
        a=a*a;
        e>>=1;
    }
    return res;
}
int main()
{
    scana(N, K);
    mat a {N, N};
    REP(i, N) REP(j, N) scan(a.m[i][j]);
    a = pow(a, K);
    REP(i, N) REP(j, N) res+=a.m[i][j];
    printf("%d\n", res);
    return 0;
}
