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
const ll MM = 2e5+10;
using namespace std;
struct edge{
    int u, w, idx;
};
ll N, a, b, w, h[2], cnt[2][MM], e[2][MM], res = 1e9; vector<edge> v[MM];
void dfs(int cur, int par){
    for(auto && i : v[cur]){
        if(i.u==par) continue;
        dfs(i.u, cur);
        cnt[i.w%2][cur]+=cnt[0][i.u]+1; cnt[(i.w+1)%2][cur]+=cnt[1][i.u];
        e[i.w%2][i.idx]+=(cnt[0][i.u]+1); e[(i.w+1)%2][i.idx]+=cnt[1][i.u];
        // end at this node
    }
    h[0]+=cnt[0][cur]; h[1]+=cnt[1][cur];
    for(auto && i : v[cur]){
        for(auto && j : v[cur]){
            if(i.u<=j.u||i.u==par||j.u==par) continue;
            int add = i.w+j.w;
            h[(add)%2]+=(cnt[0][i.u]+1)*(cnt[0][j.u]+1);
            h[(add)%2]+=(cnt[1][i.u]*cnt[1][j.u]);
            h[(add+1)%2]+=(cnt[0][i.u]+1)*(cnt[1][j.u]);
            h[(add+1)%2]+=(cnt[1][i.u])*(cnt[0][j.u]+1);

            e[(add)%2][i.idx]+=(cnt[0][i.u]+1)*(cnt[0][j.u]+1);
            e[(add)%2][i.idx]+=(cnt[1][i.u]*cnt[1][j.u]);
            e[(add+1)%2][i.idx]+=(cnt[0][i.u]+1)*(cnt[1][j.u]);
            e[(add+1)%2][i.idx]+=(cnt[1][i.u])*(cnt[0][j.u]+1);

            e[(add)%2][j.idx]+=(cnt[0][i.u]+1)*(cnt[0][j.u]+1);
            e[(add)%2][j.idx]+=(cnt[1][i.u]*cnt[1][j.u]);
            e[(add+1)%2][j.idx]+=(cnt[0][i.u]+1)*(cnt[1][j.u]);
            e[(add+1)%2][j.idx]+=(cnt[1][i.u])*(cnt[0][j.u]+1);
        }
    }
}
int main() {
    cin>>N;
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b>>w; v[a].pb({b, w%2, i}); v[b].pb({a, w%2, i});
    }
    dfs(1, -1); res = abs(h[0]-h[1]);
    for(int i = 0; i < N-1; ++i){
        res = min(res, abs(h[0]+2*e[1][i]-2*e[0][i]-h[1]));
    }
    cout<<res<<endl;
    return 0;
}
