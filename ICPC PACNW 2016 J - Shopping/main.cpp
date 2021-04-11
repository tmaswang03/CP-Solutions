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
const ll MM = 2e5+10, lg2 = 22;
using namespace std;
ll a[MM], N, M, Q, sparse[lg2][MM], LOG[MM], l, r, v;
void initsparse(){
    LOG[1] = 0;
    for(int i = 2; i <= N; ++i) LOG[i] = LOG[i/2]+1;
    for(int i = 1; i <= N; ++i) sparse[0][i] = a[i];
    for(int lg = 1; lg <= lg2; ++lg){
        int sz = 1<<lg, psz = 1<<(lg-1);
        for(int i = 1; i <= N-sz+1; ++i){
            sparse[lg][i] = min(sparse[lg-1][i], sparse[lg-1][i+psz]);
        }
    }
}

ll query (int l, int r){
    int sz = r-l+1;
    return min(sparse[LOG[sz]][l],sparse[LOG[sz]][r-(1<<LOG[sz])+1]);
}

int bsearch(int l, int r, ll v){
    int lo = l, hi = r, mid, ret = hi;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(query(lo, mid)>v) lo = mid+1;
        else{ hi = mid-1; ret = mid;}
    }
    return ret;
}

int main()
{
    scan(N); scan(Q);
    for(int i = 1; i <= N; ++i) scan(a[i]);
    initsparse();
    while(Q--){
        scana(v, l, r);
        while(query(l,r)<=v){
            l = bsearch(l, r, v);
            v%=a[l];
        }
        printf("%lld\n", v);
    }
    return 0;
}
