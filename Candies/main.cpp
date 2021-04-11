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
const ll MM = 1e5+10, MN = 1e2+10, mod = 1e9+7;
using namespace std;
ll N, K, a[MM], dp[MN][MM], pre[MM]; deque<int> dq;
int main()
{
    cin>>N>>K;
    pre[0] = 1;
    for(int i = 1; i <= N; ++i){
        cin>>a[i]; ll sum = 0, pt = K;
        for(int j = K; j >= 0; --j){
            if(j>=a[i]){
                if(dq.size()<a[i]){
                    while(dq.size()<a[i]){
                        dq.push_back(pre[pt]); sum+=pre[pt--];
                    }
                }
                else{
                    sum-=dq.front(); dq.pop_front();
                    sum+=pre[pt]; dq.push_back(pre[pt--]);
                }
            }
            else{
                sum-=dq.front(); dq.pop_front();
            }
            dp[i][j]+=sum; dp[i][j]%=mod;
        }
        for(int j = 0; j <= K; ++j) pre[j] = dp[i][j];
    }
    cout<<dp[N][K]<<endl;
    return 0;
}
