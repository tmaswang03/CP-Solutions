#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
const ll MM = 5e5+10;
using namespace std;
ll N, a[MM], pma[MM],  psum[MM], sma[MM],  ssum[MM], res = LLONG_MAX;
int main()
{
    cin>>N; fill(pma, pma+N, -1e9-10); fill(sma, sma+N, -1e9-10); ms(ssum, 0); ms(psum, 0);
    for(int i = 1; i <= N; ++i){ cin>>a[i]; pma[i] = max(pma[i-1], a[i]);}
    sma[N] = a[N];
    for(int i = N-1; i >= 1; --i) sma[i] = max(a[i], sma[i+1]);
    for(int i = N; i >= 1; --i) ssum[i] = ssum[i+1]+ sma[i]-a[i];
    for(int i = 1; i <= N; ++i) psum[i] = psum[i-1]+pma[i]-a[i];
    for(int i = 1; i <= N; ++i){
        res = min(res, psum[i] + ssum[i+1]);
    }
    cout<<res<<endl;
    return 0;
}
