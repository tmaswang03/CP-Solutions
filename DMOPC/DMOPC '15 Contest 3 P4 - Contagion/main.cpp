#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pll pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 3e3+10;
using namespace std;
ll N, X, x[MM], y[MM], Q, dst[MM], K; priority_queue<pll, vector<pll>, greater<pll> > pq;
ll sqr(ll in){ return in*in; }
ll getdst(int a, int b){ return sqr(x[a]-x[b])+sqr(y[a]-y[b]); }
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scana(x[i], y[i]);
    }
    scan(X);  --X; ms(dst, 0x3f3f3f3f3f3f3f); dst[X] = 0;
    pq.push({0, X});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.f>dst[c.s]) continue;
        for(int i = 0; i < N; ++i){
            int cost = getdst(c.s, i);
            if(c.f+cost<dst[i]){
                dst[i] = c.f+cost; pq.push({dst[i], i});
            }
        }
    }
    sort(dst, dst+N);
    scan(Q);
    while(Q--){
        scan(K);
        printf("%d\n", upper_bound(dst, dst+N, K) - dst);
    }
    return 0;
}
