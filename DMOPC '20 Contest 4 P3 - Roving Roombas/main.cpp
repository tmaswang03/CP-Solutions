#include<bits/stdc++.h>
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
const ll MM = 5e5+10;
using namespace std;
ll N, M, x, y, res, bit[MM], pt = 0; vector<pii> v, e, c;
void upd(ll x, ll val){
    for(; x < MM; x+=x&-x) bit[x]+=val;
}
ll query(ll x){
    ll ret = 0;
    for(; x > 0; x-=x&-x) ret+=bit[x];
    return ret;
}
bool cmp(pii a, pii b){
    return a < b;
}
ll gett(ll x){
    return lower_bound(c.begin(), c.end(), mp(x, 0), cmp) - c.begin() +1;
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        cin>>x>>y; c.pb({y, 1});
        v.pb({x, y});
    }
    for(int i = 0; i < M; ++i){
        cin>>x>>y; c.pb({y, 0}); e.pb({x, y});
    }
    sort(v.begin(), v.end());
    sort(e.begin(), e.end());
    sort(c.begin(), c.end());
    for(int i = 0; i < c.size(); ++i){
        if(c[i].s) upd(gett(c[i].f), 1);
    }
    for(int i = 0; i < e.size(); ++i){
        while(pt < v.size() && v[pt].f<e[i].f){
            upd(gett(v[pt].s), -1); ++pt;
        }
        res+=query(gett(e[i].s));
    }
    cout<<res<<endl;
    return 0;
}
