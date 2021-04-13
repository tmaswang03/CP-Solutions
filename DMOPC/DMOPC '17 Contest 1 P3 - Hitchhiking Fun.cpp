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
const int inf = 0x3f3f3f3f;
using namespace std;
int N, M, a, b, t; vector<pii> v[MM]; queue<int> q; pii dst[MM];
int main()
{
    cin>>N>>M;
    for(int i = 2; i <= N; ++i) dst[i] = mp(inf, inf);
    for(int i = 0; i < M; ++i){
        cin>>a>>b>>t;
        v[a].pb({b, t}); v[b].pb({a, t});
    }
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto && i : v[cur]){
            if(mp(dst[cur].f+i.s, dst[cur].s+1)<dst[i.f]){
                dst[i.f] = mp(dst[cur].f+i.s, dst[cur].s+1);
                q.push(i.f);
            }
        }
    }
    if(dst[N].f>=inf&&dst[N].s>=inf) cout<<-1<<endl;
    else cout<<dst[N].f<<" "<<dst[N].s<<endl;
    return 0;
}
