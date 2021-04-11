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
const ll MM = 2e5+10;
using namespace std;
ll a[MM], T, N, K, bst[MM], dp[MM][2]; deque<ll>dq;
int main()
{
    cin>>T;
    // dp, take this item and get best dp[i
    while(T--){
        cin>>N>>K;
        ll res = 0;
        for(int i = 0; i < N; ++i){
            cin>>a[i]; a[i+N] = a[i];
        }
        for(int i = 0; i < 2*N; ++i) a[i]+=a[i-1];
        ms(bst, 0); dq.pb(0); ms(dp, 0);
        for(int i = 0; i < 2*N; ++i){
            while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
            while(!dq.empty() && dq.front()<i-K) dq.pop_front();
            dq.push_back(i);
            bst[i] = dq.front();
        }
        // best segments if you end at the right,
        // pick the best set of segments such that none collide
        for(int i = 0; i < 2*N; ++i){
            // dp = include or not include, you can include bst[i] or don't include
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = a[i] - a[bst[i]] + max(dp[bst[i-1]][0], dp[bst[i-1]][1]);
            res = max({res, dp[i][0], dp[i][1]});
        }
        cout<<res<<endl;
    }
    return 0;
}
