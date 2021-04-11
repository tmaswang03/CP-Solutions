#include<bits/stdc++.h>
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
const ll MM = 2e5+10;
using namespace std;
int N, K, Q, bit[MM], C, pt; pii a[MM];
void upd(int x, int val){
    for(; x < MM; x+=x&-x) bit[x]+=val;
}
int query(int x){
    int res = 0;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}
struct L{
    int lft, idx, val;
};
bool cmp(L x, L y){
    return x.lft < y.lft;
}
vector<L> v;
int main()
{
    cin>>N>>K>>Q;
    for(int i = 1; i <= Q; ++i){
        cin>>a[i].f>>a[i].s>>C;
        v.pb({a[i].f, i, C}); v.pb({a[i].s+1, i, -C});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 1; i <= N; ++i){
        while(v[pt].lft <= i && pt < v.size()){
            upd(v[pt].idx, v[pt].val);
            ++pt;
        }
        int lo = 1, hi = Q, mid, res = 0x3f3f3f3f;
        while(lo <= hi){
            mid = lo+hi>>1;
            if(query(mid)>=K){
                res = min(res, mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        if(res==0x3f3f3f3f)cout<<-1<<" ";
        else cout<<res<<" ";
    }
    return 0;
}
