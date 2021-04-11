#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MAXN = 5e5+10;
const ll MOD = 1e9+7;
using namespace std;
vector<int> v[MAXN], component[MAXN];
int loot[MAXN], totloot[MAXN], lownode[MAXN], lownode1[MAXN], starttime[MAXN], time1 = 0, N, M;
bool visited[MAXN], in[MAXN];
pair<int, int > dp[MAXN][2];
stack<int>s;

void dfs(ll node){
    visited[node] = 1;
    ++time1;
    lownode1[node] = time1;
    starttime[node] = time1;
    s.push(node); in[node] = 1;
    for(auto && i : v[node]){
        if(!visited[i]){
            dfs(i);
            lownode1[node] = min(lownode1[node], lownode1[i]);
        }
        else if (in[i]) lownode1[node] = min(lownode1[node], starttime[i]);
    }
    if (lownode1[node] == starttime[node]){
        ll  t = s.top();
        while (s.top() != node){
            ll i = s.top();
            s.pop();
            in[i] = 0;
            lownode[i] = t;
        }
        s.pop();
        lownode[node] = t; in[node] = 0;
    }
}

void initscc(){
    for(ll i = 1; i <= N; ++i){
        totloot[lownode[i]]+=loot[i];
        for(auto && it : v[i]){
            if(lownode[it]!=lownode[i]){
                component[lownode[i]].pb(lownode[it]);
            }
        }
    }
}

pair<ll, ll>  recur (ll cmp, bool take){
    if(cmp == lownode[N]){
        if(take) return dp[cmp][take]  = mp(totloot[cmp],1);
        return dp[cmp][take]  = mp(0,1);
    }
    pair<ll, ll> res = dp[cmp][take];
    if(res != mp((ll)-1, (ll)-1))  return res;
    pair<ll, ll> max1 = {-1,1};
    for(auto && i : component[cmp]){
        if(take){
            res = recur(i, 0);
            res.f += totloot[cmp];
            if(res.f == max1.f) max1.s = (max1.s+res.s)%MOD;
            else if(res.f>max1.f){
                max1 = res;
            }
        }
        res = recur(i, 1);
        if(res.f==max1.f) max1.s = (max1.s+res.s)%MOD;
        else if(res.f>max1.f){
            max1 = res;
        }
    }
    return dp[cmp][take] = max1;
}

int main()
{
    scan(N); scan(M); ms(visited, 0); ms(totloot, 0); ms(in, 0);
    fill(&dp[0][0], &dp[0][0] + 2*MAXN, mp(-1, -1));
    for(int i = 1; i <= N; ++i)
        scan(loot[i]);

    for(int i = 0; i < M; ++i){
        ll a, b; scan(a); scan(b); v[a].pb(b);
    }
    for(int i = 1; i <= N; ++i)
        if(!visited[i]) dfs(i);

    initscc();
    pair<ll, ll> sol = recur(lownode[1], 1);
    cout<<sol.f<<" "<<sol.s<<endl;
    return 0;
}
