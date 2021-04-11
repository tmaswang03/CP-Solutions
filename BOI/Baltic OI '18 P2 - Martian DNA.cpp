#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MM = 2e5+5, inf = 0x3f3f3f3f;
using namespace std;
ll freq[MM], cur[MM], a[MM];
// w/ bruce
int main()
{
    ll N, K, R, l = 0, r = 0, cnt = 0, res = inf; scan(N); scan(K); scan(R);
    cnt = R;
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    for(int i = 0; i < R; ++i){
        ll b, amnt; scan(b); scan(amnt);
        freq[b] = amnt;
    }
    for(int l  = 0, r = 0; r < N-1; ++r){
        if(++cur[a[r]] == freq[a[r]]) --cnt;
        while(l <= r && cur[a[l]] > freq[a[l]]){
            --cur[a[l]]; ++l;
        }
        if(!cnt) res = min(res, r-l+1);
    }
    if(res==inf) cout<<"impossible"<<endl;
    else cout<<res<<endl;
    return 0;
}
