#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
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
const ll MM = 2e5+10, inf = 0x3f3f3f3f; // N children, 1 billion stops,
using namespace std;
// of the children denoted with a number greater than or equal to B, who is the youngest child that rode for Y or less stops?
// At stop X, child A got out
int N, Q, X, Y, t[4*MM]; char opt;
void upd (int v, int l, int r, int x, int val){
    if(l==r && r == x){
        t[v] = val; return;
    }
    int mid = l+r>>1;
    if(x<=mid) upd(v<<1, l, mid, x, val);
    else upd(v<<1|1, mid+1, r, x, val);
    t[v] = min(t[v<<1],t[v<<1|1]);
}
int query(int v, int l, int r, int lo, int hi){
    if(l>hi||r<lo) return inf;
    if(lo<=l && r <= hi) return t[v];
    int mid = l+r>>1;
    return min(query(v<<1, l, mid, lo, min(mid, hi)), query(v<<1|1, mid+1, r, max(lo, mid+1), hi));
}

int bsearch(int l, int r, int x){
    int lo = l, hi = r, ret = inf, mid;
    if(query(1, 1, N, lo, hi)>x) return -1;
    while(lo<hi){
        mid = lo+hi>>1;
        if(query(1, 1, N, lo, mid)<=x){hi = mid; ret = mid;}
        else {ret = mid+1; lo = mid+1;}
//        cout<<lo<<" "<<hi<<" "<<ret<<endl;
    }
    return ret == inf ? -1 : ret;
}
int main()
{
    ms(t, inf);
    scana(N, Q);
    while(Q--){
        scanf("%c", &opt); scana(X, Y);
        if(opt=='M') upd(1, 1, N, Y, X);
        else{
            printf("%d\n", bsearch(Y, N, X));
//            cout<<query(1, 1, N, Y, Y)<<endl;
        }
    }
    return 0;
}
