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
const ll MM = 2e3+10;
using namespace std;
ll dp[MM][MM],N, C, res = LLONG_MAX, start = 0; string in; bool a[MM][MM];
ll sqr(ll x){ return x*x; }
//  dp[i] + (i-j)^2 <= dp[k] + (k-j)^2
// dp[i] + i^2 - 2ij + j^2 <= dp[k] + k^2 -2kj + j^2
// dp[i] - dp[k] + i^2 - k^2 <= 2j(i-k)
// (dp[i] - dp[k] + i^2 - k^2) / (i-k) <= 2j
// change to o(n^2) using cht
// do cht on one column at a time using prev column
// do back and forth (state on row i can be obtained from a value c>x>i)
long double gett(int a, int b, int x){
    return (ld) (dp[a][x] - dp[b][x] + sqr(a) - sqr(b)) / (ld) (a-b);
}
int main()
{
    boost()
    cin>>N>>C;
    for(int i = 0; i < C; ++i){
        cin>>in;
        for(int j = 0; j < N; ++j){
            a[i][j] = (in[j]=='1');
        }
    }
    // 1st : row
    // 2nd : column
    ms(dp, 0x3f3f3f3f3f3f3f3f);
    vector<ll> hull;
    for(int i = 0; i < C; ++i){
        if(a[i][0]) dp[i][0] = 0;
    }
    for(int i = 1; i < N; ++i){
        hull.clear(); start = 0;
        for(int j = 0; j < C; ++j){
            if(a[j][i-1] && a[j][i]) dp[j][i] = dp[j][i-1];
            while(start <= (ll) hull.size() - 2) {
                ll line1 = hull[start], line2 = hull[start+1];
                if(gett(line2,line1, i-1) < (ld) 2*j) ++start;
                else break;
            }
            if(start < hull.size() && a[j][i]){
                dp[j][i] = min(dp[j][i], dp[hull[start]][i-1] + sqr(j - hull[start]));
            }
            if(a[j][i-1]){
                while(start <= (ll) hull.size() - 2) {
                    ll A = hull[hull.size()-2], B = hull[hull.size()-1];
                    if(gett(A, B, i-1)>=gett(B, j, i-1)) hull.pop_back();
                    else break;
                }
                hull.pb(j);
            }
        }
        hull.clear(); start = 0;
        for(int j = C-1; j >= 0; --j){
            while(start <= (ll) hull.size() - 2) {
                ll line1 = hull[start], line2 = hull[start+1];
                if(gett(line2,line1, i-1) >= (ld) 2*j) ++start;
                else break;
            }
            if(start < hull.size() && a[j][i]){
                dp[j][i] = min(dp[j][i], dp[hull[start]][i-1] + sqr(hull[start] - j));
            }
            if(a[j][i-1]){
                while(start <= (ll) hull.size() - 2) {
                    ll A = hull[hull.size()-2], B = hull[hull.size()-1];
                    if(gett(A, B, i-1)<=gett(B, j, i-1)) hull.pop_back();
                    else break;
                }
                hull.pb(j);
            }
        }
    }
    for(int i = 0; i < C; ++i){
        res = min(res, dp[i][N-1]);
    }
    cout<<res<<endl;

    return 0;
}