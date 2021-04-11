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
const ll MM = 2e5+10, mod = 1e9+7;
using namespace std;
ll N, M, dsta[MM], dstb[MM], x, y, cnt, K, ans = 1; vector<ll> v[MM]; queue<ll> q;
int main()
{
    cin>>N>>M>>K; ms(dsta, 0x3f3f3f); ms(dstb, 0x3f3f3f);
    for(int i = 0; i < M; ++i){
        cin>>x>>y; v[x].pb(y); v[y].pb(x);
    }
    q.push(1); dsta[1] = 0; dstb[N] = 0;
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(auto && i : v[c]){
            if(dsta[i]>dsta[c]+1){
                dsta[i] = dsta[c]+1; q.push(i);
            }
        }
    }
    q.push(N);
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(auto && i : v[c]){
            if(dstb[i]>dstb[c]+1){
                dstb[i] = dstb[c]+1; q.push(i);
            }
        }
    }
    for(int i = 2; i < N; ++i){
        if(dstb[i]<=K&&dsta[i]<=K) ++cnt;
    }
    for(int i = 0; i < cnt; ++i){
        ans = (ans*2)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
