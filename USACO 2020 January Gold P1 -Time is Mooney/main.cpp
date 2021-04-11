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
const ll MM = 1e3+10;
using namespace std;
int m[MM], N, M, C, a, b, best[MM], days[MM]; vector<int>v[MM]; queue<pii> q;
int sqr(int n){ return n*n;}
int main()
{
    cin>>N>>M>>C;
    for(int i = 1; i <= N; ++i) cin>>m[i];
    for(int i = 0; i < M; ++i){
        cin>>a>>b; v[a].pb(b);
    }
    q.push({1, 0});
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(auto && i : v[c.f]){
            if(best[c.f]+m[i]-C*sqr(c.s+1)>best[i]-C*sqr(days[i])){
                best[i] = best[c.f]+m[i]; days[i] = c.s+1;
                q.push({i, c.s+1});
            }
        }
    }
    cout<<best[1]-C*sqr(days[1])<<endl;
    return 0;
}
