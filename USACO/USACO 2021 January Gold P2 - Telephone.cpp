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
const ll MM = 5e4+10;
using namespace std;
int N, K, a[MM], dst[MM]; bool adj[55][55]; string in; vector<int> v[55];
priority_queue<pii, vector<pii>, greater<pii> > q;
int main()
{
    boost();
    cin>>N>>K; ms(dst, 0x3f3f3f3f); dst[0] = 0;
    for(int i = 0; i < N; ++i) cin>>a[i];
    for(int i = 1; i <= K; ++i){
        cin>>in;
        for(int j = 0; j < in.length(); ++j){
            adj[i][j+1] = (bool)(in[j]-'0');
        }
    }
    for(int i = 0; i < N; ++i) v[a[i]].pb(i);
    q.push({0, 0});
    while(!q.empty()){
        int c = a[q.top().f], idx = q.top().f, cur = q.top().s; q.pop();
        if(dst[idx]< cur) continue;
        for(int j = 1; j <= K; ++j){
            if(!adj[c][j]) continue;
            for(auto && k : v[j]){
                if(dst[idx]+abs(k-idx) < dst[k]){
                    dst[k] = dst[idx]+abs(k-idx);
                    q.push({k, dst[k]});
                }
            }
        }
    }
    if(dst[N-1] != 0x3f3f3f3f) cout<<dst[N-1]<<endl;
    else cout<<-1<<endl;
    return 0;
}
