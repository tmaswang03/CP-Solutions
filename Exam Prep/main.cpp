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
const ll MM = 1e6+10;
using namespace std;
ll opt, hed[MM], rnk[MM], sum[MM], a, b, N, Q;
ll get(int x){
    if(hed[x] == x) return x;
    return hed[x] = get(hed[x]);
}

void join(int x, int y){
    x = get(x); y = get(y);
    if(x==y) return;
    if(rnk[x]<rnk[y]) swap(x, y);
    hed[y] = hed[x];
    rnk[x] += rnk[y];
    sum[x] += sum[y];
}

int main()
{
    scana(N, Q);
    for(int i = 1; i <= N; ++i){
        rnk[i] = 1; hed[i] = i; scan(sum[i]);
    }
    while(Q--){
        scana(opt, a);
        if(opt==1){
            scan(b);
            join(a, b);
        }
        else if(opt==2) printf("%lld\n", rnk[get(a)]);
        else printf("%lld\n", sum[get(a)]);
    }
    return 0;
}
