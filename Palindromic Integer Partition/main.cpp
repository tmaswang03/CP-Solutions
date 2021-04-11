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
const ll MM = 70;
using namespace std;
ll N, dp[MM];
ll solve(int c){
    if(dp[c]!=-1) return dp[c];
    ll res = 1;
    for(int i = 1; i <= c/2; ++i){
        res += solve(c-2*i);
    }
    return dp[c] = res;
}
int main()
{
    cin>>N; ms(dp, -1);
    cout<<solve(N)<<endl;
    return 0;
}
