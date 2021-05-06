#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
const ll MM = 2e5+10, MN = 1e6+10;
using namespace std;
ll N, K, a, b, w, sz[MM], psa[MM], freq[MN], res[MM], tot;
vector<pll> v[MM]; bool blocked[MM]; stack<ll> st; stack<pll> rst;
ll getsz(ll cur, ll par){
    sz[cur] = 1;
    for(auto && i : v[cur]){
        if(i.f==par||blocked[i.f]) continue;
        sz[cur]+=getsz(i.f, cur);
    }
    return sz[cur];
}

ll getcnt(ll cur, ll par, ll msz){
    for(auto && i : v[cur]){
        if(i.f==par||blocked[i.f]) continue;
        if(sz[i.f]>msz/2) return getcnt(i.f, cur, msz);
    }
    return cur;
}
void dfs(int cur, int par, int len, int cnt, bool run){
    // cur = current node, par is parent, len is total tourists rn
    // cnt = centroid (for updating n stuff)
    if(len>K) return;
    st.push(len); rst.push({len, cur});
    if(len==K && run){
        ++psa[cur]; ++psa[cnt];
    }
    if(freq[K-len]){
        psa[cur]+=freq[K-len];
    }
    for(auto && i : v[cur]){
        if(blocked[i.f]||i.f==par) continue;
        dfs(i.f, cur, len+i.s, cnt, run);
    }
}
void push_up(ll cur, ll par){
    for(auto && i : v[cur]){
        if(i.f==par||blocked[i.f]) continue;
        push_up(i.f, cur);
        psa[cur]+=psa[i.f];
    }
    res[cur]+=psa[cur];
}
void solve(ll cur, ll par){
    ll msz = getsz(cur, par);
    ll cnt = getcnt(cur, par, msz);
    blocked[cnt] = 1;
    for(auto && i : v[cnt]){
        if(blocked[i.f]||i.f==par) continue;
        dfs(i.f, cnt, i.s, cnt, 1);
        while(!st.empty()){
            ++freq[st.top()]; st.pop();
        }
    }
    while(!rst.empty()){
        freq[rst.top().f]=0; rst.pop();
    }
    for(int i = v[cnt].size()-1; i>=0; --i){
        if(blocked[v[cnt][i].f]||v[cnt][i].f==par) continue;
        dfs(v[cnt][i].f, cnt, v[cnt][i].s, cnt, 0);
        while(!st.empty()){
            ++freq[st.top()]; st.pop();
        }
    }
    push_up(cnt, par);
    res[cnt]-=psa[cnt]/2; tot+=psa[cnt]/2;
    while(!rst.empty()){
        freq[rst.top().f] = 0; psa[rst.top().s] = 0; rst.pop();
    }
    for(auto && i : v[cnt]){
        if(!blocked[i.f]) solve(i.f, cnt);
    }
}
ll ggcd(ll a, ll b){
    if(b==0) return a;
    return ggcd(b, a%b);
}
int main()
{
    scanf("%lld %lld", &N, &K);
    for(int i = 0; i < N-1; ++i){
        scanf("%lld %lld %lld", &a, &b, &w); v[a].pb({b, w}); v[b].pb({a, w});
    }
    solve(1, -1);
    for(int i = 1; i <= N; ++i){
        if(res[i]==0){
            printf("0 / 1\n");
        }
        else{
            ll gcd = ggcd(res[i], tot);
            printf("%lld / %lld\n", res[i]/gcd, tot/gcd);
        }
    }
}