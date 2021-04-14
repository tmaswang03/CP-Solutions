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
ll T, a[3][MM], N[3], res;
ll sqr(ll in){ return in*in; }
void solve(int h, int j, int k){
    int b1 = 0;
    for(int i = 0; i < N[h]; ++i){
        ll r = a[h][i];
        ll g1 = a[j][lower_bound(a[j], a[j]+N[j], r) - a[j]];
        while(b1 < N[k]-1 && sqr(r-a[k][b1+1])+sqr(r-g1)+sqr(a[k][b1+1]-g1) <= sqr(r-a[k][b1])+sqr(r-g1)+sqr(a[k][b1]-g1)){
            res = min(res, sqr(r-a[k][b1])+sqr(r-g1)+sqr(a[k][b1]-g1));
            ++b1;
        }
        res = min(res, sqr(r-a[k][b1])+sqr(r-g1)+sqr(a[k][b1]-g1));
    }
}
int main()
{
    cin>>T;
    while(T--){
        res = LLONG_MAX;
        for(int i = 0; i < 3; ++i) cin>>N[i];
        for(int i = 0; i < 3; ++i){
            ms(a[i], 0);
            for(int j = 0; j < N[i]; ++j) cin>>a[i][j];
            sort(a[i], a[i]+N[i]);
        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(j==i) continue;
                for(int k = 0; k < 3; ++k){
                    if(k==j||k==i) continue;
                    solve(i, j, k);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
