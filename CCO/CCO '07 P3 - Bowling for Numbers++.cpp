#include<bits/stdc++.h>
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
const ll MN = 1e4+210;
using namespace std;
ll T, N, W, K, dpp[510][MN], ppsa[MN], a[MN];
int main()
{
    cin>>T;
    while(T--){
        cin>>N>>K>>W; ll res = 0; ms(a, 0); ms(ppsa, 0); ms(dpp, 0);
        for(int i = 1; i <= N; i++) cin>>a[i];
        for(int i = W+1; i <= N+2*W; ++i) ppsa[i] = ppsa[i-1] + a[i-W];
        for(int i = 1; i <= K; i++) {
            for(int j = 1; j <= N+2*W; j++) {
                ll lft1 = max(0LL, j-W), lft2 = max(0LL, j-2*W);
                dpp[i][j] = max({dpp[i-1][j], dpp[i][j-1], dpp[i-1][lft1] + ppsa[j] - ppsa[lft1]});
                if(i>1){
                    for(int k = lft1; k >= lft2; --k){
                        dpp[i][j] = max(dpp[i][j], dpp[i-2][k] + ppsa[j] - ppsa[k]);
                    }
                }
                res = max(res, dpp[i][j]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}