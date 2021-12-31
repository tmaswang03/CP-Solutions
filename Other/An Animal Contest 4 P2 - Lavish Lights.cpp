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
ll N, Q, a[MM], T, LCM[MM], idx;
ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}
int main()
{
    boost();
    cin>>N>>Q; LCM[0] = 1; idx = N + 1;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i) {
        LCM[i] = LCM[i-1] / gcd(LCM[i-1], a[i]) * a[i];
        if(LCM[i] < 0 || LCM[i] > 1e9) {
            idx = i; break;
        }
    }
    for(int i = idx; i <= N; ++i) LCM[i] = LLONG_MAX;
    while(Q--) {
        cin>>T;
        int lo = 1, hi = N, mid = 0, res = -1;
        while(hi >= lo) {
            mid = (lo+hi+1)>>1;
            if(T % LCM[mid] == 0) lo = mid + 1;
            else {
                hi = mid - 1; res = mid;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}