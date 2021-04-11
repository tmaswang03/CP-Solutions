#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define lg(n) 31 - __builtin_clz(n) ;
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
const ll MM = 1e5+10, LOG = 20;
using namespace std;
int a[MM], tb[LOG][MM], N, M, l, r;
int lg(int n){return 31 - __builtin_clz(n);}
void init(){
    for(int i = 1; i <= N; ++i) tb[0][i] = a[i];
    for(int l = 1; l < LOG; ++l)
        for(int i = 1; i <= N-(1<<l)+1; ++i) tb[l][i] = max(tb[l-1][i], tb[l-1][i+(1<<(l-1))]);
}

int query(int l, int r){ return max(tb[lg(r-l+1)][l], tb[lg(r-l+1)][r-(1<<lg(r-l+1))+1]);}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i) scanf("%d", &a[i]);
    init();
    while(M--){
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}
