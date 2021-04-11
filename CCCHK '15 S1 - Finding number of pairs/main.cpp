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
const ll MM = 1e5+10, mod = 1e9+7;
using namespace std;
ll a[MM], bit[MM*2], M, N, cnt = 0; vector<ll>v;
void upd(int x){ for(; x < 2*MM; x+=x&-x){ ++bit[x]; bit[x]%=mod;}}
ll query(int x){
    ll res = 0;
    for(; x>0; x-=x&-x) res = (res+bit[x])%mod;
    return res%mod;
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; ++i){ cin>>a[i]; v.pb(a[i]); v.pb(M-a[i]);}
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < N; ++i){
        cnt = (cnt + query(lower_bound(v.begin(), v.end(), M-a[i]) - v.begin()+1))%mod;
        upd(lower_bound(v.begin(), v.end(), a[i])-v.begin()+1);
    }
    cout<<cnt%mod<<endl;
    return 0;
}
