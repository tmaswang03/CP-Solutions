#include<bits/stdc++.h>
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
const ll MM = 2e5+10;
using namespace std;
int N, M, a, b, res; vector<pii> v[MM]; vector<int> out;
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= M; ++i){
        cin>>a>>b; v[a].pb({a, i}); v[b].pb({b, i});
    }
    for(int i = 0; i <= (1<<M); ++i){
        int cur = 0;
        for(int j = 1; j <= N; ++j){
            int cnt = 0;
            for(auto && it : v[j]){
                if(i&(1<<it.s)) continue;
                ++cnt;
            }
            cur+=cnt%2;
        }
        if(cur>res){
            res = cur; out.clear();
            for(int k = 0; k <= M; ++k){
                if(i&(1<<k)) out.pb(k);
            }
        }
    }
    cout<<res<<endl;
    cout<<out.size()<<endl;
    for(auto && i : out) cout<<i<<" ";
    return 0;
}
