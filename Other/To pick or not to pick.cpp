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
const ll MM = 1e5+10, inf = 1e5+1;
using namespace std;
int N, dp[MM], freq[MM], a[MM];
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i) {
        cin>>a[i]; ++freq[a[i]];
    }
    dp[1] = freq[1];
    for(int i = 2; i <= inf; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + freq[i] * i);
    }
    cout<<dp[inf]<<endl;
    return 0;
}