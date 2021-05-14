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
const ll MM = 5e5+10, inf = 0x3f3f3f3f3f3f3f;
using namespace std;
// from oly
vector<pii> v[MM]; ll n, sz[MM], pa[MM], lvl[MM], dst[20][MM], res = LLONG_MAX, dp[MM]; bool blok[MM];
int getsz(int u, int p){
    sz[u] = 1;
    for(auto && i : v[u]){
        if(i.f==p||blok[i.f]) continue;
        sz[u]+=getsz(i.f, u);
    }
    return sz[u];
}
int getcnt(int u, int p, int tot){
    for(auto && i : v[u]){
        if(blok[i.f]||i.f==p) continue;
        if(sz[i.f]*2>tot) return getcnt(i.f, u, tot);
    }
    return u;
}
void getdis(int u, int p, int l, ll d){
    dst[l][u] = d;
    for(auto && i : v[u]){
        if(i.f == p || blok[i.f]) continue;
        getdis(i.f, u, l, d+i.s);
    }
}
void solve(int cur, int par, int l){
    getsz(cur, -1); int cnt = getcnt(cur, -1, sz[cur]);
    blok[cnt] = 1; pa[cnt] = par; lvl[cnt] = l;
    getdis(cnt, -1, l, 0);
    for(auto && i : v[cnt]){
        if(blok[i.f]) continue;
        solve(i.f, cnt, l+1);
    }
}
void Init(int N, int A[], int B[], int D[]){
    n = N; ms(dp, inf);
    for(int i = 0; i < N-1; ++i){
        v[A[i]].pb({B[i], D[i]}); v[B[i]].pb({A[i], D[i]});
    }
    solve(0, -1, 0);
}
long long Query(int S, int X[], int T, int Y[]){
    res = inf; stack<int> st;
    for(int i = 0; i < S; ++i){
        int cur = X[i], l = lvl[cur];
        for(; cur!=-1; cur = pa[cur], --l){
            dp[cur] = min(dp[cur], dst[l][X[i]]); st.push(cur);
        }
    }
    for(int i = 0; i < T; ++i){
        int cur = Y[i], l = lvl[cur];
        for(; cur!=-1; cur = pa[cur], --l){
            res = min(res, dp[cur]+dst[l][Y[i]]);
        }
    }
    while(!st.empty()){ dp[st.top()] = inf; st.pop(); }
    return res;
}
int main()
{
    int N, A[MM], B[MM], D[MM];
    int Q, S, X[MM], T, Y[MM];
    cin>>N>>Q;
    for(int i = 0; i < N-1; ++i) cin>>A[i]>>B[i]>>D[i];
    Init(N, A, B, D);
    while(Q--){
        cin>>S>>T;
        for(int i = 0; i < S; ++i) cin>>X[i];
        for(int i = 0; i < T; ++i) cin>>Y[i];
        cout<<Query(S, X, T, Y)<<endl;
    }
}

