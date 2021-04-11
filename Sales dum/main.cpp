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
const ll MM = 3e5+10;
using namespace std;
int dp[60], p[MM], va[MM], a, b, l, r, N, D, B, cnt[60]; set<pii, greater<pii> > st[60];
int main()
{

    scana(B, N, D);
    for(int i = 1; i <= N; ++i){
        scana(p[i], va[i]);
        st[p[i]].insert({va[i], i});
    }
    while(D--){
        scana(a, b, l, r);
        st[p[a]].erase({va[a],a});
        p[a] = b; st[p[a]].insert({va[a], a});
        ms(dp, 0);
        for(int i = 1; i <= B; ++i){
            int cnt = 0;
            for(auto && it : st[i]){
                if(it.s<l || it.s>r) continue;
                ++cnt;
                for(int k = B; k >= i; --k) dp[k] = max(dp[k], dp[k-i]+it.f);
                if(cnt>B/i+1) break;
            }
        }
        printf("%d\n", dp[B]);
    }
    return 0;
}
