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
const ll mod = 1e9+7, MM = 1e7+10;
using namespace std;
ll N, P, Q, diff[MM], a[MM], psa[MM], days = 0, sum;

int main()
{
    cin>>N>>P>>Q;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i){
        sum+=diff[i];
        ll val = a[i]+sum-days, num = (N-i+1)*P/Q;
        days+=val;
        diff[N-num+1]+=2*val;
        cout<<days%mod<<" ";
    }
    return 0;
}
