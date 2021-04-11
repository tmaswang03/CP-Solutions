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
typedef pair<ll, ll> pll;
ll N, L, res = 0; pll a[MM];
int main()
{
    cin>>N>>L;
    // minimize the amount of time you go backwards
    // best choice is to drop off at next customer's start point if the end point is > start
    // if the customer goes backwards then send customer backwards res+=2*(s-e)
    // slowly bring everyone back and forth
    for(int i = 0; i < N; ++i) cin>>a[i].f>>a[i].s;
    sort(a, a+N);
    return 0;
}
