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
const ll MM = 5e3+10;
using namespace std;
ll N, K, Q, r, c; pair<long double, long double> a[MM], b[MM];
int main()
{
    cin>>N>>K>>Q;
    for(int i = 0; i < K; ++i) {
        cin>>a[i].f>>a[i].s>>b[i].f>>b[i].s;
    }
    while(Q--) {
        cin>>r>>c;
        // follow the square backwards
        // 90 degrees counterclockwise
        // -y, x
        for(int i = K-1; i >= 0; --i) {
            if(a[i].f <= r && a[i].s <= c && b[i].f >= r && b[i].s>=c) {
                // in square
                long double offr = (b[i].f + a[i].f) / 2.0, offc = (b[i].s + a[i].s) / 2.0;
                long double tmpr = (long double)(r) - offr, tmpc = (long double)(c) - offc;
                r = -1.0*tmpc + offr; c = tmpr + offc;
            }
        }
        cout<<(r - 1) * N + c<<endl;
    }
    return 0;
}