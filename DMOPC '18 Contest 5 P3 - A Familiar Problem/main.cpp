#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
ll N, M, sum, res;
int main()
{
    scan(N); scan(M);
    deque<ll>dq;
    for(int i = 0; i < N; ++i){
        ll a; scan(a);
        while(!dq.empty() && sum + a >= M){
            sum -= dq.front(); dq.pop_front();
        }
        dq.pb(a); sum += a;
        if(sum < M) res = max(res, (ll)dq.size());
    }
    printf("%lld\n", res);
    return 0;
}
