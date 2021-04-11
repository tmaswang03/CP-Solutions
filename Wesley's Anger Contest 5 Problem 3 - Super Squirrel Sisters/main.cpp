#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+1;
using namespace std;
ll a[MM], freq[MM];
ll sqr(ll in){return in*in;}
int main()
{
    ll N, res = 0; scan(N);  ms(freq, 0);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    for(ll len = 1; sqr(len) <= N; ++len){
        ll cnt = 0; ms(freq, 0);
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            if(freq[a[i]]==len) --cnt;
            ++freq[a[i]];
            if(freq[a[i]]==len) ++cnt;
            dq.pb(i);
            if(dq.size()>sqr(len)){
                if(freq[a[dq.front()]]==len)--cnt;
                --freq[a[dq.front()]];
                if(freq[a[dq.front()]]==len)++cnt;
                dq.pop_front();
            }
            if(cnt==len) ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}
