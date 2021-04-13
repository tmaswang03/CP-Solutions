#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
struct que{
    int l, r, m, idx;
};
bool cmp(que &a, que &b){return a.m > b.m;}
ll N, bit[MM], Q, res[MM], pt = 0;
vector<pair<int, int> >v; vector<que> qs;
ll query (ll x) {
    ll ret = 0;
    for (;x>0;x-=x&-x) ret += bit[x];
    return ret;
}
void upd (ll x, ll v){
    for (;x<=MM-10;x+=x&-x) bit[x] += v;
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){
        int a; scan(a);
        v.pb({a, i});
    }
    cin>>Q;
    for(int i = 0; i < Q; ++i){
        int l,r,m; cin>>l>>r>>m;
        ++l; ++r;
        qs.pb({l,r,m, i});
    }
    sort(v.begin(), v.end(), greater<pair<int, int> >()); sort(qs.begin(), qs.end(), cmp);
    for(auto && c : qs){
        while(v[pt].f >= c.m && pt < v.size()){
            upd(v[pt].s, v[pt].f); ++pt;
        }
        res[c.idx] = query(c.r) - query(c.l-1);
    }
    for(int i = 0; i < Q; ++i){
        cout<<res[i]<<endl;
    }
    return 0;
}
