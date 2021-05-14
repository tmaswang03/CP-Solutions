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
const ll MM = 1e3+10;
using namespace std;
int N, a[MM], dp[MM][MM], psa[MM];
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){
        cin>>a[i]; psa[i] = a[i]+psa[i-1];
        dp[i][i] = a[i];
        for(int j = i-1; j >= 1; --j){
            dp[j][i] = max(a[j] - dp[j+1][i], a[i] - dp[j][i-1]);
        }
    }
    cout<<(psa[N] - dp[1][N])/2+dp[1][N]<<endl;
    return 0;
}