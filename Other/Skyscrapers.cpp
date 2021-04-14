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
using namespace std;
int M, N, r[MM], cur, psa[MM], ans1, ans2, c, C;
// for max, x, y = min(r[i], y[i])
// for min x, y = max(r[i], y[i])
int main()
{
    cin>>M>>N>>c>>C;
    for(int i = 1; i <= M; ++i) cin>>r[i];
    sort(r+1, r+M+1);
    for(int i = 1; i <= M; ++i) psa[i] = psa[i-1] + r[i];
    for(int i = 0; i < N; ++i){
        cin>>cur;
        int idx = upper_bound(r+1, r+M+1, cur) - r;
        ans1 += C*psa[idx-1]; ans1+= C*cur*(M-idx+1);
        ans2 += c*psa[idx-1]; ans2+= c*cur*(M-idx+1);
    }
    cout<<ans2<<" "<<ans1<<endl;
    return 0;
}
