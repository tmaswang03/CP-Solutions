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
const ll MM = 1e5+10;
using namespace std;
int cnt, N, M, a, b, hed[MM]; vector<int> v[MM]; bool vis[MM];
void mark(int cur){
    queue<int> q; vis[cur] = 1; q.push(cur);
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(auto && i : v[c]){
            if(vis[i]) continue;
            vis[i] = 1; q.push(i);
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; ++i){
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    }
    for(int i = 1; i <= N; ++i){
        if(vis[i]) continue;
        hed[cnt++] = i;
        mark(i);
    }
    cout<<cnt-1<<endl;
    for(int i = 0; i < cnt-1; ++i){
        cout<<hed[i]<<" "<<hed[i+1]<<endl;
    }
    return 0;
}
