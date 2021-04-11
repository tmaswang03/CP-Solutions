#include<bits/stdc++.h>
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
const ll MM = 1e6+10;
using namespace std;
int N, bit[MM], P;
ll psa[MM], res;
unordered_map<ll, ll> umap;
vector<ll>v;
int get(ll i){return lower_bound(v.begin(), v.end(), i) - v.begin()+1;}
void upd(ll x){for(; x<=v.size(); x+=x&-x) ++bit[x];}
int query(int x){
    int res = 0;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}

int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i) scan(psa[i]);
    scan(P);
    for(int i = 1; i <= N; ++i){
        psa[i]-=P;
        psa[i]+=psa[i-1];
        v.pb(psa[i]);
    }
    v.pb(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    upd(get(0));
    for(int i = 1; i <= N; ++i){
        int cur = get(psa[i]);
        res+=query(cur); upd(cur);
    }
    printf("%lld\n", res);
    return 0;
}
