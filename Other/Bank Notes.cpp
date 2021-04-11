#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e4+10, MN =2e2+10; ;
using namespace std;
int N, C, dp[MM], a[MM], b[MM];
int main()
{
    ms(dp, 0x3f3f3f3f3f);
    dp[0] = 0;
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    for(int i = 0; i < N; ++i){
        scan(b[i]);
    }
    scan(C);
    for(int i = 0; i < N; ++i){
        int sum = 0;
        for(int k = 1; k <= b[i]>>1; k<<=1){
            for(int j = C; j >= a[i]*k; --j){
                dp[j] = min(dp[j], dp[j-a[i]*k]+k);
            }
            sum+=k;
        }
        sum = b[i]-sum;
        for(int j = C; j >= a[i]*sum; --j){
                dp[j] = min(dp[j], dp[j-a[i]*sum]+sum);
        }
    }
    printf("%d\n", dp[C]);
    return 0;
}
