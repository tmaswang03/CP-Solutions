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
const ll MM = 1e6+10;
using namespace std;
int dpn[3*MM][2], dpdn[3*MM][2], N, K, a, b, mid;
// numerator, denominator a/b
void fiks(int x, int cur){
    ll tmp = __gcd(dpdn[x][cur], dpn[x][cur]);
    if(tmp){ dpn[x][cur]/=tmp; dpdn[x][cur]/=tmp; }
}
int main()
{
    cin>>N>>K>>a>>b; dpdn[N][1] = dpn[N][1] = dpdn[N][0] = dpn[N][0] = 1;
    for(int i = 0; i < N; ++i){
        int pre = (i+1)%2, cur = i%2;
        for(int j = 0; j <= N+K; ++j){
            dpn[j][cur]=dpn[j-1][pre]*a+dpn[j+1][pre]*(b-a);
            dpdn[j][cur]=dpdn[j+1][pre]*b+dpdn[j-1][pre]*b;
            fiks(j, cur);
            cout<<j<<" "<<dpn[j][cur]<<" "<<dpdn[j][cur]<<endl;
        }
    }
    cout<<dpdn[N+K][(N+1)%2]<<" "<<dpn[N+K][(N+1)%2]<<endl;
    return 0;
}
