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
using namespace std;
string s; int dp[300][300], len, res;
// given dp[l][r] if l==r dp[l][r] = 1;
// else find a point that has s[l] == s[r],
// dp[l][r] = max(dp[l][r], dp[l+1][r-1]) where dp holds the biggest palindrome within a range

int main()
{
    for(int t = 0; t < 5; ++t){
        cin>>s; len = s.length(); ms(dp, 0); res = 0;
        for(int r = 0; r < len; ++r){
            for(int l = r; l >= 0; --l){
                if(l==r) dp[l][r] = 1;
                else if(s[l]==s[r]){
                    if(l==r-1) dp[l][r] = 2;
                    else{
                        for(int l1 = l+1; l1 < r; ++l1){
                            for(int r1 = l1; r1 < r; ++r1){
                                int tmp = dp[l1][r1];
                                dp[l][r] = max(dp[l][r], tmp+2);
                            }
                        }
                    }
                }
                res = max(res, dp[l][r]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
