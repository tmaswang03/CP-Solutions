#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pll pair<long long, long long>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
ll N, K, a[MM], dp[MM], psa[MM], ma[MM]; priority_queue<pll> pq;
// dp[i] maximum if you pick ith element
int main()
{
    cin>>N>>K;
    for(int i = 1; i <= N; ++i) {
        cin>>a[i]; psa[i] = a[i] + psa[i-1];
    }
    for(int i = 1; i <= N; ++i) {
        while(!pq.empty() && pq.top().s <= i-K) pq.pop();
        if(i-2>0) pq.push({ma[i-2] - psa[i-1], i});
        else pq.push({-psa[i-1], i});
        if(!pq.empty()) dp[i] = psa[i] + pq.top().f;
        else dp[i] = a[i];
//        for(int j = i; j > max(i-K, 0LL); --j) {
//            if(j-2>0) dp[i] = max(dp[i], psa[i] - psa[j-1] + ma[j-2]);
//            else dp[i] = max(dp[i], psa[i] - psa[j-1]);
//        }
        ma[i] = max(ma[i-1], dp[i]);
    }
    cout<<ma[N]<<endl;
    return 0;
}