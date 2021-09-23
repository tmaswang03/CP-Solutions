#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f;
using namespace std;
char _;
int arr[MAXN]; ll psa[2*MAXN]; deque< pair<ll, ll> > dq;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0); ms(psa, 0);
    int N, K;ll res = -INF; cin>>N>>K;
    for(int i = 0; i < N; ++i) cin>>arr[i];
    for(int i = 0; i < N+K+2; ++i){
        psa[i]=arr[i%N]; psa[i]+=psa[i-1];
    }
    dq.push_back({0, -1});
    for(int i = 0; i < N+K+2; ++i){
        res = max(res, psa[i] - dq.front().first);
        while(!dq.empty() && i - dq.front().second >= K) dq.pop_front();
        while(!dq.empty() && dq.back().f >= psa[i]) dq.pop_back();
        dq.push_back({psa[i], i});
    }
    cout<<res<<endl;
    return 0;
}