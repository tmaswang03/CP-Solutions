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
const ll MM = 5e3+10;
using namespace std;
int N, dp[MM], last[30], len; string s;
int main()
{
    cin>>N; dp[0] = 1;
    while(N--){
        cin>>s; ms(last, -1); len = s.length();
        for(int i = 1; i <= len; ++i){
            dp[i] = dp[i-1]*2;
            if(last[s[i-1]-'a']!=-1){
                dp[i]-=dp[last[s[i-1]-'a']];
            }
            last[s[i-1]-'a'] = i-1;
        }
        cout<<dp[len]<<endl;
    }
    return 0;
}
