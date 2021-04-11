#include<bits/stdc++.h>
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
const ll MM = 4e5+10;
using namespace std;
vector<int>v[MM];
int N, M, Q;
bool yes[MM];
void dfs(int cur){
    yes[cur] = 1;
    for(auto && i : v[cur]){
        if(yes[i]) continue;
        dfs(i);
    }
}
int main()
{
    scan(N); scan(M); scan(Q);
    for(int i = 0; i < M; ++i){
        int a,b; scan(a); scan(b);
        v[a].pb(b);
    }
    dfs(1);
    while(Q--){
        char opt;
        scanf("%c", &opt);
        if(opt=='+'){
            int a,b; scan(a); scan(b);
            v[a].pb(b);
            if(yes[a]) dfs(a);
        }
        else{
            int a; scan(a);
            printf(yes[a] ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
