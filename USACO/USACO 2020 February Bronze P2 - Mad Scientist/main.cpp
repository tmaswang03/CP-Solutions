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
const ll MM = 1e3+10;
using namespace std;
string str1, str2; bool a[MM]; int cnt = 0, psa[MM], N, dp[MM];
vector<int> v;
int main()
{
    cin>>N>>str1>>str2; ms(dp, 0x3f3f3f); dp[0] = 0;
    for(int i = 0; i < N; ++i) a[i] = str1[i]==str2[i];
    v.pb(0);
    v.pb(a[0]);
    for(int i = 0; i < N; ++i){
        if(a[i]!=a[i-1]) v.pb(a[i]);
    }
    for(int i = 1; i < v.size(); ++i) psa[i]=v[i]+psa[i-1];
    for(int i = 1; i < v.size(); ++i){
        for(int j = 0; j < i; ++j){
            int rng = i - j;
            dp[i] = min(dp[i], dp[j] + rng - psa[i]+psa[j]); // how many aren't in right place
            dp[i] = min(dp[i], dp[j] + psa[i] - psa[j] + 1);
        }
    }
    cout<<dp[v.size()-1]<<endl;
    return 0;
}
