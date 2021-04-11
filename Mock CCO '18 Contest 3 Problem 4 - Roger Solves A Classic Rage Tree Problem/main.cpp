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
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 5e4+10, lg2 = 16;
using namespace std;
ll a[MM], N, M, sparse[MM][lg2], sparse1[MM][lg2], LOG[MM], Q, res, l, r;
void initsparse(){
    LOG[1] = 0;
    for(int i = 2; i <= N; ++i) LOG[i] = LOG[i/2]+1;
    for(int i = 1; i <= N; ++i){ sparse[i][0] = a[i]; sparse1[i][0] = a[i];}
    for(int lg = 1; lg <= lg2; ++lg){
        ll sz = 1<<lg, psz = 1<<(lg-1);
        for(int i = 1; i <= N-sz+1; ++i){
            sparse[i][lg] = max(sparse[i][lg-1], sparse[i+psz][lg-1]);
            sparse1[i][lg] = min(sparse1[i][lg-1], sparse1[i+psz][lg-1]);
        }
    }
}

ll query (int l, int r){
    ll sz = r-l+1, hi, lo;
    hi =  max(sparse[l][LOG[sz]],sparse[r-(1<<LOG[sz])+1][LOG[sz]]);
    lo = min(sparse1[l][LOG[sz]],sparse1[r-(1<<LOG[sz])+1][LOG[sz]]);
    return hi - lo;
}

int main()
{
    scan(N); scan(Q);
    for(int i = 1; i <= N; ++i) scan(a[i]);
    initsparse();
    while(Q--){
        scan(l); scan(r);
        printf("%lld\n", query(l, r));
    }
    return 0;
}
