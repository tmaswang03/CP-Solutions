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
int N, D, x, dst[MM];  vector<int> v[MM];
int dfs(int cur, int par){
    deque<int> dq; int res = 0;
    for(auto && i : v[cur]){
        if(i==par) continue;
        res+=dfs(i, cur);
        dq.push_back(dst[i]+1);
    }
    sort(dq.begin(), dq.end());
    while(dq.size()>1 && dq[0]+dq[1]<D){
        dq.pop_front(); --res;
    }
    if(dq.empty()) dst[cur] = 0;
    else dst[cur] = dq.front()%D;
    if(dst[cur]) return res;
    else return res+1;
}
int main()
{
    cin>>N>>D;
    for(int i = 2; i <= N; ++i){
        cin>>x; ++x;
        v[x].pb(i); v[i].pb(x);
    }
    cout<<dfs(1, -1)<<endl;
    return 0;
}
