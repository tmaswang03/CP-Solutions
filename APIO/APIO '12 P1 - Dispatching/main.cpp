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
const ll MM = 1e5+10;
using namespace std;
ll N, M, b[MM], c[MM], l[MM], sz[MM], strt, res, tmp; vector<int> v[MM]; priority_queue<ll>pq[MM];
// idea : the structure is shape of graph
// dfs down from the first dood
// pick each node as the leader, multiply by the most amount of people in subtrees, get max
// get most amount in subtrees
void dfs(int cur){
    ll mul = l[cur], cnt = c[cur];
    pq[cur].push(c[cur]);
    for(auto && i : v[cur]){
        dfs(i);
        if(pq[i].size()>pq[cur].size()){
            swap(cnt, tmp); swap(pq[i], pq[cur]);
        }
        while(!pq[i].empty()){
            int cst = pq[i].top(); pq[i].pop();
            if(cnt+cst>M&&pq[cur].top()>cst){
                cnt-=pq[cur].top(); pq[cur].pop();
                pq[cur].push(cst); cnt+=cst;
            }
            else if(cnt+cst<=M){ pq[cur].push(cst); cnt+=cst; }
        }
    }
    tmp = cnt;
    res = max(res, mul*(ll)(pq[cur].size()));
}
int main()
{
    scana(N, M);
    for(int i = 1; i <= N; ++i){
        scana(b[i], c[i], l[i]);
        if(!b[i]) strt = i;
        v[b[i]].pb(i);
    }
    dfs(strt);
    printf("%lld\n", res);
    return 0;
}
