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
using namespace std;
ll R, C, K, lx = 1, hx = 1, ly, hy, ans = LLONG_MAX, cnt;
ll query(ll x, ll y) {
    ll res;
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>res;
    return res;
}
int main()
{
    cin>>R>>C>>K;
    hx = R; hy = C;
    while(lx < hx || ly < hy) {
        ++cnt;
        assert(cnt <= K);
        ll mx = (lx + hx + 1) >> 1, my = (ly + hy + 1) >> 1;
        ll cc = query(mx, my), uc, rc;

        if(mx - 1 < 1) uc = cc;
        else uc = query(mx-1, my);

        if(my - 1 < 1) rc = cc;
        else rc = query(mx, my - 1);

        if(uc < cc) hx = mx - 1;
        else lx = mx;

        if(rc < cc) hy = my - 1;
        else ly = my;

        ans = min({ans, cc, uc, rc});
    }
    cout<<"! "<<ans<<endl;
    return 0;
}