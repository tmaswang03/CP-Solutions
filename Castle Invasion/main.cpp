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
ll N, r[MM], psa[MM], c, ans, maxc;
int main()
{
    // each cell is min(r[i], c[i])
    cin>>N; ms(psa, 0);
    for(int i = 1; i <= N; ++i) cin>>r[i];
    sort(r+1, r+N+1);
    for(int i = 1; i <= N; ++i) psa[i] = psa[i-1]+r[i];
    for(int i = 0; i < N; ++i){
        cin>>c; maxc = max(maxc, c);
        if(c>r[N]) {cout<<-1<<endl; return 0;}
        int idx = upper_bound(r+1, r+N+1, c) - r;
        ans += psa[idx-1]; ans+= c*(N-idx+1);
    }
    if(maxc < r[N]){cout<<-1<<endl; return 0;}
    cout<<ans<<endl;
    return 0;
}
