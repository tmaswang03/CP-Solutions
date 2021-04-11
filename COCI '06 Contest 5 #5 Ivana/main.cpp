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
const ll MM = 5e2+10;
using namespace std;
int N, a[MM], dp[MM][MM], psa[MM], res; bool iv, win[MM][MM];
bool check(int strt){
    for(int i = strt-N+1; i <= strt; ++i){
        if(!win[i][i+N-1]) return 0;
    }
    return 1;
}
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){ cin>>a[i]; a[i] = a[i]%2; a[N+i] = a[2*N+i] = a[i];}
    for(int i = 1; i <= 3*N; ++i) psa[i]+=psa[i-1]+a[i];
    iv = N%2;
    for(int strt = N+1; strt <= 2*N; ++strt){
        ms(dp, 0); ms(win, 0); dp[strt][strt] = a[strt];
        for(int l = strt; l > strt-N; --l){
            for(int r = strt; r < N+l; ++r){
                if(a[l]+psa[r]-psa[l]-dp[l+1][r]>dp[l][r]&&l<strt){
                    dp[l][r] = a[l]+psa[r]-psa[l]-dp[l+1][r];
                }
                if(a[r]+psa[r-1]-psa[l-1]-dp[l][r-1]>dp[l][r]&&r>strt){
                    dp[l][r] = a[r]+psa[r-1]-psa[l-1]-dp[l][r-1];
                }
            }
            if((iv && 2*dp[l][N+l-1]>psa[N])||(!iv && 2*dp[l][N+l-1]<psa[N])){
                ++res; break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
