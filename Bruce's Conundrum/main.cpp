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
const ll MN = 150, MM = 1e5+10, MT = 1e4+10;
using namespace std;
int t[MN], N, M , T, k, idx;
double dp[MT], a[MN], res, add;
int main()
{
    scana(N, M, T);
    for(int i = 1; i <= N; ++i) scan(t[i]);
    for(int i = 1; i <= M; ++i){
        scan(k); if(!k) ++add;
        for(int j = 1; j <= k; ++j){scan(idx); a[idx]+=1/(1.0*k);}
    }
    for(int i = 1; i <= N; ++i){
        for(int j = T; j >= t[i]; --j){
            dp[j] = max(dp[j], dp[j-t[i]]+a[i]); res = max(res, dp[j]);
        }
    }
    printf("%.2lf", res+add);
    return 0;
}
