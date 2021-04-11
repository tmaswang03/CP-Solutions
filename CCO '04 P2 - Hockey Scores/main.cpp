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
using namespace std;
const ll MM = 1e3+10;
int N, S, cnt; pii a[MM]; vector<pii>v[MM];
bool cmp(pii &x, pii &y){
    if(max(x.f, x.s)==max(y.f, y.s)) return min(x.f, x.s) < min(y.f, y.s);
    return (max(x.f, x.s)< max(y.f, y.s));
}
int main()
{
    scanf("%d\n", &N);
    while(N--){
        scanf("%d\n", &S); cnt = 0;
        for(int i = 0; i < S; i++){
            v[i].clear(); scanf("%d-%d", &a[i].f, &a[i].s);
            if(a[i].f <  a[i].s) swap(a[i].f, a[i].s);
        }
        sort(a, a+S, cmp); v[cnt].pb(a[0]);
        for(int i = 1; i < S; ++i){
            int nxt = cnt+1;
            for(int j = 0; j <= cnt; ++j){
                auto c = v[j].back();
                if(max(c.f,c.s) <= max(a[i].f, a[i].s) && min(c.f, c.s) <= min(a[i].f, a[i].s)){
                    nxt = j; break;
                }
            }
            cnt = max(cnt, nxt);
            v[nxt].pb(a[i]);
        }
        printf("%d\n", cnt+1);
        for(int i = 0; i <= cnt; ++i){
            for(auto && j : v[i]) {
                printf("%d-%d ", j.f, j.s);
            }
            printf("\n");
        }
    }
    return 0;
}
