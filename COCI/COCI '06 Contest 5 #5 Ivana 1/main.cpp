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
const ll MM = 1e2+10;
using namespace std;
int N, a[MM], dp[MM][MM], psa[MM];
int recur(int l, int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l==0 && r==N+1) return 0;
    // you can either pick r+1 or l-1
    int res = 0;
    if(l>=1) res = max(res, psa[N]-psa[r]+psa[l-1]-recur(l-1, r)+a[l]);
    if(r<=N) res = max(res, psa[N]-psa[r]+psa[l-1]-recur(l, r+1)+a[r]);
    return dp[l][r] = res;
}
int main()
{
    cin>>N; ms(dp, -1);
    for(int i = 1; i <= N; ++i){ cin>>a[i]; a[i] = a[i]%2;}
    for(int i = 1; i <= N; ++i) psa[i]+=psa[i-1]+a[i];
    for(int i = 1; i <= N; ++i){
        if(a[i]+dp[i][i]>)
    }
    return 0;
}
