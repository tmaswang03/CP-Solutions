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
vector<int> v[MM]; int N, e;
bool inq[MM], vis[MM];
bool dfs(int cur){
    if(vis[cur]) return 0;
    inq[cur] = 1; vis[cur] = 1;
    for(auto && i : v[cur]){
        if(inq[i]) return 1;
        if(dfs(i)) return 1;
    }
    inq[cur] = 0;
    return 0;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin>>e; if(e)v[i].pb(j);
        }
    }
    for(int i = 0; i < N; ++i){
        if(dfs(i)){ cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
    return 0;
}
