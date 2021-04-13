#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f;
using namespace std;
char _;
int arr[MAXN]; ll psa[2*MAXN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0); ms(psa, 0);
    int N, K;ll res = -INF; cin>>N>>K;
    priority_queue<pair<ll,ll>,  vector<pair<ll, ll > >, greater<pair<ll, ll> > > pq;
    for(int i = 0; i < N; ++i) cin>>arr[i];
    for(int i = 0; i < 2*N; ++i){
        psa[i]=arr[i%N]; psa[i]+=psa[i-1];
    }
    pq.push({0, -1});
    for(int i = 0; i < 2*N; ++i){
        res = max(res, psa[i] - pq.top().first);
        while(i - pq.top().second >= K){
            pq.pop();
        }
        pq.push({psa[i], i});
    }
    cout<<res<<endl;
    return 0;
}
