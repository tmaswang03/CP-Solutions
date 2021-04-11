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
const ll MM = 600, MU = 200;
using namespace std;
int dp[MM][MU], M, U, R, V, T, F, res = 0; // dp states =  time, food
int main()
{
    scana(M, U, R);
    for(int i = 0; i < R; ++i){
        scana(V, T, F);
        for(int t = M; t>= T; --t){
            for(int f = U; f >= F; --f){
                dp[t][f] = max(dp[t][f], dp[t-T][f-F]+V);
                res =  max(res, dp[t][f]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
