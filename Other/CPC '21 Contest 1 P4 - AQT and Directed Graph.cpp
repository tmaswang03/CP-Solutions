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
const ll MM = 3e5+10;
using namespace std;
int N, M, a, b, ans[MM]; vector<int> v[MM]; pii res = {0, 0};
void dfs(int cur, int best){
    for(auto && i : v[cur]){
        if(best > ans[i] && best > i){
            ans[i] = best; res = max(res, mp(i, ans[i]));
            dfs(i, best);
        }
    }
}
int main()
{
    boost();
    cin>>N>>M;
    for(int i = 0; i < M; ++i){
        cin>>a>>b; v[b].pb(a);
    }
    for(int i = N; i >= 1; --i) dfs(i, i);
    if(res != mp(0, 0)) cout<<res.f<<" "<<res.s<<endl;
    else cout<<-1<<endl;
    return 0;
}