#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const ll MM = 2e5+1, ML = 1e6+10;
using namespace std;
int N, sz[MM], res = 1e9, freq[ML], k, H[MM][2], L[MM];
bool blocked[MM];
struct edge{
    int nd, len;
};
vector<edge> v[MM];
stack<pair<int, int> >st;
stack<int>st2;

int getsz(int cur, int par){
    sz[cur] = 1;
    for(auto && i : v[cur]){
        if(i.nd == par || blocked[i.nd]) continue;
        sz[cur]+=getsz(i.nd, cur);
    }
    return sz[cur];
}

int getcnt(int cur, int par, int sze){
    for(auto && i : v[cur]){
        if(i.nd == par || blocked[i.nd]) continue;
        if(sz[i.nd]>sze/2) return getcnt(i.nd, cur, sze);
    }
    return cur;
}

void dfs(int cur, int par, int dist, int roads){
    if(dist>k) return;
    st.push({dist, roads});
    st2.push(dist);
    res = min(res, roads + freq[k-dist]);
    for(auto && i : v[cur]){
        if(blocked[i.nd] || i.nd == par ) continue;
        dfs(i.nd, cur, dist + i.len, roads+1);
    }
}

void solve(int cur, int par){
    ms(freq, 0x3f3f3f3f); freq[0] = 0;
    int siz = getsz(cur, par);
    int cnt = getcnt(cur, par, siz);
    blocked[cnt] = 1;
    for(auto && i : v[cnt]){
        if(blocked[i.nd] || i.nd == par) continue;
        dfs(i.nd, cnt, i.len, 1);
        while(!st.empty()){
            freq[st.top().f] = min(freq[st.top().f], st.top().s);
            st.pop();
        }
    }
    while(!st2.empty()){
        freq[st2.top()] = 0x3f3f3f;
        st2.pop();
    }
    for(auto && i : v[cnt]){
        if(!blocked[i.nd]) solve(i.nd, cnt);
    }
}

int best_path(int N, int K, int H[][2], int L[]){
    ms(blocked, 0);
    k = K;
    for(int i = 0; i < N-1; ++i){
        v[H[i][0]].pb({H[i][1], L[i]});
        v[H[i][1]].pb({H[i][0], L[i]});
    }
    solve(0, -1);
    if(res==1e9) res = -1;
    return res;
}

int main()
{
    scan(N); scan(k);
    for(int i = 0; i < N-1; ++i){
        scan(H[i][0]); scan(H[i][1]);
        scan(L[i]);
    }
    cout<<best_path(N, k, H, L)<<endl;
    /*
    4 3
    0 1 1
    1 2 2
    1 3 4
    */
    return 0;
}
