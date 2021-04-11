#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 9;
using namespace std;
vector<int> v[MM];
bool vis[MM], inq[MM], pos = 1;
stack<int>s;
void dfs(int cur){
    inq[cur] = 1;
    for(auto && i : v[cur]){
        if(inq[i]){pos = 0; continue;}
        if(vis[i]) continue;
        dfs(i);
    }
    vis[cur] = 1; s.push(cur);
    inq[cur] = 0;
}

int main()
{
    v[1].pb(7); v[1].pb(4); v[2].pb(1); v[3].pb(4); v[3].pb(5);
    for(;;){
        int a,b; scan(a); scan(b);
        if(!a) break;
        v[a].pb(b);
    }
    for(int i = 7; i >= 1; --i){
        if(!vis[i]) dfs(i);
    }
    if(!pos) printf("Cannot complete these tasks. Going to bed.\n");
    else{
        while(!s.empty()){
            printf("%d ", s.top()); s.pop();
        }
    }
    return 0;
}
