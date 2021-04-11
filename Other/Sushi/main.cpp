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
const ll MM = 3e2+10;
using namespace std;
int N, a[MM], sum; double dp[3*MM][MM][5], mul, res, nul;
// probability of having x amount of sushi when there is i sushi total left
int main()
{
    cin>>N; mul = 1.0/N; // probability of having a useful turn
    for(int i = 0; i < N; ++i){ cin>>a[i]; sum+=a[i]; }
    for(int i = 0; i < N; ++i) dp[0][i][a[i]] = 1;
    // the probability of having k sushis on a plate on the ith turn is equal to
    // the probability of having k+1 sushis on a plate on the i-1 turn
    // multiplied by the probability of picking the plate
    // probability of staying the same is then the probability of having i plate
    // the probability of having a useful pick is then 1 - probabilities of not rolling a 0
    for(int i = 1; i <= sum; ++i){
        for(int k = 0; k < N; ++k){
            for(int val = 3; val >= 0; --val){
                if(val>0) dp[i][k][val] = dp[i-1][k][val]*(1.0-mul);
                else dp[i][k][val] = dp[i-1][k][val];
                dp[i][k][val] += dp[i-1][k][val+1]*mul;
                cout<<dp[i][k][val]<<" ";
            }cout<<endl;
        }cout<<endl;
    }
    for(int i = 1; i <= sum; ++i){
        nul = 0; // probability of having a useless turn = sum of values of plates with 0;
        for(int k = 0; k < N; ++k) nul+=dp[i-1][k][0]*mul;
        cout<<1/(1-nul)<<endl;
        res+=1.0/(1-nul);
    }
    cout<<res<<endl;
    return 0;
}
