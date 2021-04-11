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
const ll MM = 2e5+10;
using namespace std;
typedef pair<ll, ll> pll;
ll b[MM], sm[MM][2], pm[MM][2], N, srt[MM]; pll a[MM];
int main()
{
    cin>>N; ms(sm, 0); ms(pm, 0);
    for(int i = 1; i <= N+1; ++i){ cin>>a[i].f; a[i].s = i;}
    for(int i = 1; i <= N; ++i) cin>>b[i];
    sort(a+1, a+N+2); sort(b+1, b+N+1);
    for(int i = 1; i <= N+1; ++i) srt[a[i].s] =  i;
    for(int i = 1; i <= N+1; ++i){
        pm[i][0] = max(pm[i-1][0], max(0LL, a[i].f-b[i]));
        pm[i][1] = max(pm[i-1][1], max(0LL, a[i+1].f-b[i]));
    }
    for(int i = N; i >= 1; --i){
        sm[i][0] = max(sm[i+1][0], max(0LL, a[i].f-b[i]));
        sm[i][1] = max(sm[i+1][1], max(0LL, a[i+1].f-b[i]));
    }
    for(int i = 1; i <= N+1; ++i){
        cout<<max(pm[srt[i]-1][0],sm[srt[i]][1])<<" ";
    }
    return 0;
}
