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
#define pll pair<long long, long long>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
ll N, M, cur, a1, b1, c1, d1, a2, b2, c2, d2, lo, hi, cnt, r; vector<pll> v, a;
// x.a, x.b, x.c, x.d;
// x.a*1e9+x.b*1e6+x.c*1e3+x.d;
// sort by the left coordinate, bsearch for the
bool cmp(pll a, pll b){
    return a.f<=b.f;
}
int main()
{
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%lld.%lld.%lld.%lld-%lld.%lld.%lld.%lld", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2);
        lo = 1e9*a1+1e6*b1+1e3*c1+d1; hi = 1e9*a2+1e6*b2+1e3*c2+d2;
        a.pb({lo, hi});
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size();){
        r = i+1;
        while(r<a.size()&&a[i].s>=a[r].f){
            a[i].s = max(a[i].s, a[r].s);
            ++r;
        }
        v.pb({a[i].f, 0}); v.pb({a[i].s, 1});
        i = r;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < M; ++i){
        scanf("%lld.%lld.%lld.%lld", &a1, &b1, &c1, &d1);
        cur = 1e9*a1+1e6*b1+1e3*c1+d1;
        int ptr = lower_bound(v.begin(), v.end(), mp(cur, 0), cmp)-v.begin();
        if(v[ptr].f==cur||v[ptr].s==1) ++cnt;
    }
    printf("%lld\n", cnt);
    return 0;
}
