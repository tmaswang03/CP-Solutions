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
const ll MM = 1e5+10;
using namespace std;
pii a[MM]; int  res = 0, N, bit[MM], last[MM];
void upd(int l, int val){
    for(; l < MM; l+=l&-l) bit[l]+=val;
}
int query(int l){
    int res = 0;
    for(; l > 0; l-=l&-l) res+=bit[l];
    return res;
}
int range(int l, int r){ return query(r)-query(l-1); }


int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scana(a[i].f, a[i].s); res = 0;
        int r = query(a[i].s), l = query(a[i].f);
        res+=r-last[a[i].s]; res+=l-last[a[i].f];
        last[a[i].s] = r; last[a[i].f] = l;
        upd(a[i].f+1,1); upd(a[i].s, -1);
        printf("%lld\n", res);
    }
    return 0;
}
