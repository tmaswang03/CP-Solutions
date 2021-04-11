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
const ll MM = 1e6+10;
using namespace std;
vector<int> v[MM]; ll V, E, a, b, res;
int main()
{
    boost();
    cin>>V>>E;
    for(int i = 0; i < E; ++i){
        cin>>a>>b; v[a].pb(b); v[b].pb(a);
    }
    for(int i = 1; i <= V; ++i){
        for(auto && j : v[i]){
            if(j <= i) continue;
            for(auto && k : v[j]){
                if(k <= j) continue;
                for(auto && h : v[k]){
                    if(h==i) ++res;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
