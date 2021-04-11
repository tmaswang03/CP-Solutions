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
const ll MM = 2e5+10, LOG = 20;
using namespace std;
int lg2(int n){return 31-__builtin_clz(n);}
ll t[LOG][MM], N, Q, l, r;
int main()
{
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i) cin>>t[0][i];
    for(int i = 1; i < LOG; ++i){
        for(int j = 1; j <= N-(1<<i)+1; ++j){
            t[i][j] = min(t[i-1][j], t[i-1][j+(1<<(i-1))]);
        }
    }
    while(Q--){
        cin>>l>>r; int sz = lg2(r-l+1);
        cout<<min(t[sz][l], t[sz][r-(1<<sz)+1])<<endl;
    }
    return 0;
}
