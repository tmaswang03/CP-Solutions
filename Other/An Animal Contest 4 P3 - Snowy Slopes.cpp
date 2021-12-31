#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
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
ll N, M, res; pair<int, int> a[MM], b[MM]; unordered_map<ll, ll> mp; set<pair<ll, ll> > st;
// y2 - y1 = k*x
// x2 - x1 = d*x
// run through all M
// each coord is of form y = k/d * x + b
// b = y - k/d*x
// b = (y*d - k*x) / d
// b*d = y*d - k*x;
// find b of the coordinate
// find the number of matching bs

int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; ++i) cin>>a[i].f>>a[i].s;
    for(int i = 0; i < M; ++i) {
        cin>>b[i].f>>b[i].s; ll gcd = __gcd(b[i].f, b[i].s);
        st.insert({b[i].f/gcd, b[i].s/gcd});
    }

    for(auto && i : st) {
        for(int j = 0; j < N; ++j) {
            res += mp[a[j].s*i.s - a[j].f*i.f];
            ++mp[a[j].s*i.s - a[j].f*i.f];
        }
        mp.clear();
    }
    cout<<res<<endl;
    return 0;
}