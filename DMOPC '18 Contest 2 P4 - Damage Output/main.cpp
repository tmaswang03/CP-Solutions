#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
using namespace std;

int main()
{
    ll N, M, len = 0x3f3f3f3f, sum = 0, counter; scan(N); scan(M);
    deque<ll>dq;
    for(int i = 0; i < N; ++i){
        ll a; scan(a);
        if(sum < M){
            dq.pb(a); sum+=a;
        }
        else{
            dq.pb(a); sum+=a;
            while(sum-dq.front()>=M){
                sum-=dq.front(); dq.pop_front();
            }
        }
        if(sum >= M){
            len = min(len, (ll)dq.size());
        }
    }
    printf(len==0x3f3f3f3f ? "-1\n" : "%lld\n", len);
    return 0;
}
