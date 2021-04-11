#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const ll MM = 4e5+10;
using namespace std;
ll N, dp[MM], a, b, idx, dia, freq[MM], sz[MM], res; bool blocked[MM];
vector<ll> v[MM]; stack<ll> st, st2;

void getd(ll c, ll len, ll p){
    if(len > dia){dia = len; idx = c;}
    for(auto && i : v[c]){
        if(i==p) continue;
        getd(i, len+1, c);
    }
}

ll getsz(ll c, ll p){
    sz[c] = 1;
    for(auto && i : v[c]){
        if(i==p||blocked[i]) continue;
        sz[c]+=getsz(i, c);
    }
    return sz[c];
}

ll getcnt(ll c, ll p, ll sze){
    for(auto && i : v[c]){
        if(i==p||blocked[i]) continue;
        if(sz[i]>sze/2) return getcnt(i, c, sze);
    } return c;
}

void dfs(ll c, ll p, ll len){
    st.push(len); st2.push(len);
    if(len==dia) res+=1;
    res+=freq[dia-len];
    for(auto && i : v[c]){
        if(i==p||blocked[i]) continue;
        dfs(i, c, len+1);
    }
}

void solve(ll c, ll p){
    ll siz = getsz(c, p);
    ll cnt = getcnt(c, p, siz);
    blocked[cnt] = 1;
    for(auto && i : v[cnt]){
        if(i==p||blocked[i]) continue;
        dfs(i, cnt, 1);
        while(!st.empty()){
            ++freq[st.top()]; st.pop();
        }
    }
    while(!st2.empty()){
        freq[st2.top()] = 0; st2.pop();
    }
    for(auto && i : v[cnt]){
        if(!blocked[i]) solve(i, cnt);
    }
}

int main()
{
    scan(N);
    for(int i = 0; i < N-1; ++i){
        scan(a); scan(b); v[a].pb(b); v[b].pb(a);
    }
    getd(1, 0, -1); dia = 0;
    getd(idx, 0, -1);
    solve(1, -1);
    cout<<dia+1<<" "<<res<<endl;
    return 0;
}
