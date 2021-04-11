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
const ll MM = 5e3+10, MN = 1e6+10;
using namespace std;
int N, x, res, cnt[MN]; vector<int>v; bool vis[2*MN];
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){ cin>>x; v.pb(x); vis[x] = 1; ++cnt[x];}
    sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); ++i){
        if(cnt[v[i]]>1) res+=vis[2*v[i]];
        for(int j = 0; j < i; ++j){
            res+=vis[v[i]+v[j]];
        }
    }
    if(res!=0) cout<<res<<endl;
    else cout<<-1<<endl;
    return 0;
}
