#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<long long, long long>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
ll a[MM], N, ma, res = 1e18, hed[MM], sz[MM], mid; pii tmp[MM];
int find_par(int a){
    if(hed[a]==a) return a;
    return hed[a] = find_par(hed[a]);
}
void join(int a, int b){
    a = find_par(a); b = find_par(b);
    if(sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b]; hed[b] = a;
}
bool cmp(pii a, pii b){
    return a < b;
}
bool solve(ll diff){
    for(int i = 0; i < N; ++i){
        hed[i] = i; sz[i] = 1;
    }
    for(int i = 1; i < N; ++i){
        if(tmp[i].f  - tmp[i-1].f <= diff){
            join(tmp[i].s, tmp[i-1].s);
        }
    }
    for(int i = 0; i < N; ++i){
        int pt = lower_bound(tmp, tmp+N, mp(a[i], i), cmp) - tmp;
        if(find_par(i)!=find_par(pt)) return 0;
    }
    return 1;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; tmp[i] = mp(a[i], i);
    }
    sort(tmp, tmp+N);
    ll lo = 0, hi = 1e18;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(solve(mid)){
            res = min(res, mid); hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    cout<<res<<endl;

    return 0;
}
