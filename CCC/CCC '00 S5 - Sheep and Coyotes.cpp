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
const ll MM = 1e3+10;
const ld eps = 1e-16;
using namespace std;
int N; pair<ld, ld> a[MM]; bool vis[MM]; vector<int> v;
ld calc(ld x1, ld y1, ld x2, ld y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void run(ld x) {
    ld r = 1e9+10; v.clear();
    for(int i = 0; i < N; ++i) {
        ld tmp = calc(x, 0, a[i].f, a[i].s);
        if(tmp + eps < r) {
            r = tmp; v.clear();
            v.pb(i);
        }
        else if(tmp + eps >= r && tmp - eps <= r) v.pb(i);
    }
    for(auto && i : v) vis[i] = 1;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i) {
        cin>>a[i].f>>a[i].s;
    }
    for(ld i = 0; i <= 1000; i += 0.01) run(i);
    for(int i = 0; i < N; ++i) {
        if(vis[i]) {
            cout<<fixed<<setprecision(2)<<"The sheep at ("<<a[i].f<<", "<<a[i].s<<") might be eaten."<<endl;
        }
    }
    return 0;
}