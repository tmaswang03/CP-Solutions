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
const ll MM = 1e5+10;
using namespace std;
ll N, M, T, tot, ans; pair<ll, ll> a[MM]; priority_queue<ll, vector<ll>, greater<ll> > pq;
// sort list by distance
// distance p, take the top i values such that
// T*i <= M - 2*p
/*
5 200 1
100 100
101 100
102 100
103 100
104 100
*/
int main()
{
    cin>>N>>M>>T;
    for(int i = 0; i < N; ++i) cin>>a[i].f>>a[i].s;
    sort(a, a+N);
    for(int i = 0; i < N; ++i) {
        ll dst = a[i].f, cst = a[i].s; pq.push(cst); tot += cst;
        while(!pq.empty() && T*(ll)(pq.size()) > M - 2*dst) {
            tot -= pq.top(); pq.pop();
        }
        ans = max(ans, tot);
    }
    cout<<ans<<endl;
    return 0;
}