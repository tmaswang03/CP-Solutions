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
const ll MM = 3e4+10, ML = 510;
using namespace std;
int psa[MM], dp[MM][ML], t, n, k, w; pii r[MM][ML];
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>k>>w; ms(dp, 0);
        for(int i = 0; i < n; ++i){cin>>psa[i]; psa[i]+=psa[i-1];}
        for(int lvl = 1; lvl <= k; ++lvl){
            // iterate through how many throws you have,
            // the best previous throw right <= the right of current throw
            //the result is max{dp[lvl-1][] }
            for(int lft = 0; lft < n-w+1; ++lft){
            }
        }
    }
    return 0;
}
