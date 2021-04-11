#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MAXN = 8388618;
const ll INF = 0x3f3f3f3f;
using namespace std;
ll dp[MAXN], arr[MAXN], pre[MAXN];
int main()
{
    ll N, K; scan(N); scan(K);
    for(int i = 1; i <= N; ++i){
        scan(arr[i]);
    }
    deque<int> dq; stack<int>res;
    dp[0] = 0; pre[0] = -1; dq.pb(0); arr[N+1] = 0;
    for(int i = 1; i <= N+1; ++i){
        while(!dq.empty() && dq.front()<i-K) dq.pop_front();
        dp[i] = dp[dq.front()]+arr[i];
        pre[i] = dq.front();
        while(!dq.empty() && dp[dq.back()]>=dp[i]) dq.pop_back();
        dq.pb(i);
    }
    cout<<dp[N+1]<<endl;
    int ind = N+1;
    while(ind!=-1){
        ind = pre[ind];
        res.push(ind);
    }
    res.pop(); res.pop();
    while(!res.empty()){
        int temp1 = res.top(); res.pop();
        printf("%lld ", temp1);
    }
    return 0;
}
