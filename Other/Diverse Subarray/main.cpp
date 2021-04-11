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
const ll MM = 2e5+10, shft = 1e6+10, LOG = 20;
using namespace std;
int a[MM], last[2*shft], N, Q, l, r, t[LOG][MM];;
int lg2(int n){ return 31 - __builtin_clz(n);}
// after preprocessing the question is given
// given a range l, r find the maximum array value l <= i <= r;
// a[i] = min(a[i], i-l+1);
int query(int l, int r){
    int sz = lg2(r-l+1);
    return max(t[sz][l], t[sz][r-(1<<(sz))+1]);
}
int main()
{
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++i){ scanf("%d", &a[i]);  a[i]+=shft;}
    for(int i = 1; i <= N; ++i){
        t[0][i] = min (i-last[a[i]], t[0][i-1]+1);
        last[a[i]] = i;
    }
    for(int l = 1; l < LOG; ++l){
        for(int i = 1; i <= N; ++i){
            t[l][i] = max(t[l-1][i], t[l-1][i+(1<<(l-1))]);
        }
    }
    while(Q--){
        scanf("%d%d", &l, &r); int res = 0;
        for(int pt = l; pt <= r ; ++pt){
            if(pt-t[0][pt]>=l){ res = max(res, query(pt, r)); break;}
            res = pt-l+1;
        }
        printf("%d\n", res);
    }
    return 0;
}
