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
const ll MM = 1e4+10, shft = 1e4+10;
using namespace std;
ll N, bit[MM][MM+shft], a[MM], res, cnt; vector<int> v;
void upd(int x){
    for(; x < MM+shft; x+=x&-x) ++bit[x];
}
ll query(int x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}
int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i) scan(a[i]);
    for(int i = 1; i <= N; ++i){
        cnt = 0; ms(bit, 0); upd(shft);
        // for every number keep a counter of how many there are so far
        // then find how many indeces on the left such that
        // (psa[i]-psa[j])> (i-j)/2;
        // psa[i] -i/2 > psa[j]-j/2;
        // where i is the current index
        // j is the left, i = right
        for(int j = 1; j <= N; ++j){
            cnt+=(a[j]==i);
            res+=query(2*cnt-j+shft-1);
            upd(2*cnt-j+shft);
        }
    }
    printf("%lld\n", res);
    return 0;
}
