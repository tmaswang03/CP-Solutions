#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 60;
using namespace std;
bool v[MM][MM], vis[MM];
int N, M;
queue<pair<int, int> > query;
int main()
{
    scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        int a, b; scan(a); scan(b); v[a][b] = 1;
        query.push({a,b});
    }
    while(!query.empty()){
        ms(vis, 0);
        auto c = query.front(); query.pop();
        v[c.f][c.s] = 0;
        queue<int> q;
        q.push(1); vis[1] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i = 0; i <= N; ++i){
                if(v[cur][i] && !vis[i]){
                    q.push(i); vis[i] = 1;
                }
            }
        }
        v[c.f][c.s] = 1;
        printf(vis[N] ? "YES\n" : "NO\n");
    }
    return 0;
}
