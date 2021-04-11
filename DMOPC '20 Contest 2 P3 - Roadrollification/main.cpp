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
const ll MM = 2e5+10;
using namespace std;
ll a[MM], N, sz[MM],rsz[MM], valfrom[MM],x,y, res = 0, tot; vector<int>v[MM], rv[MM];
ll dfs(int cur){
    if(sz[cur]!=-1) return sz[cur];
    ll cnt = a[cur]*(a[cur]-1), cnt1 = a[cur];
    for(auto && i : v[cur]){
        cnt+=a[cur]*dfs(i);
        cnt1+=dfs(i);
    }
    valfrom[cur] = cnt;
    tot+=cnt;
    return sz[cur] = cnt1;
}
ll dfsr(int cur){
    if(rsz[cur]!=-1) return rsz[cur]+a[cur];
    ll cnt = 0, cnt1 = 0;
    for(auto && i : rv[cur]){
        cnt1+=dfsr(i);
    }
    rsz[cur] = cnt1;
    return cnt1+a[cur];
}
int main()
{
    cin>>N; ms(valto, -1); ms(valfrom, -1); ms(sz, -1); ms(rsz, -1);
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 0; i < N-1; ++i){
        cin>>x>>y;
        v[x].pb(y); rv[y].pb(x);
    }
    for(int i = 1; i <= N; ++i) dfsr(i);
    for(int i = 1; i <= N; ++i) dfs(i);
    for(int i = 1; i <= N; ++i){
        for(auto && j : v[i]){
            res = max(res, tot+(sz[i]-sz[j])*(rsz[j]-rsz[i]+a[j]-a[i]));
        }
    }
    cout<<res<<endl;
    return 0;
}
