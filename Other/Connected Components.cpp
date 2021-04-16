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
const ll MM = 1e3+10;
using namespace std;
int N, e, t,c;
bool vis[MM];
vector<int> v[MM], out;
stack<int>s;
void dfs(int n){
    vis[n]=1; out.pb(n);
    for(auto && i : v[n]){
        if(vis[i]) continue;
        dfs(i);
    }
}

int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            scan(e);
            if(e) v[i].pb(j);
        }
    }
    for(int i = 1; i <= N; ++i){
        if(vis[i]) continue;
        dfs(i);
        sort(out.begin(), out.end());
        for(auto && j : out){
            cout<<j<<" ";
        }cout<<endl;
        out.clear();
    }
    return 0;
}
