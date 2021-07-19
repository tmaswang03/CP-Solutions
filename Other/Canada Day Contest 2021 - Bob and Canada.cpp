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
const ll MM = 8e5+10;
using namespace std;
int psa[MM][2], T, mi, res, N; string str;
// for 2 points l, r
// result = psa[l][0] + psa[r][1] - psa[l][1] + psa[N][0] - psa[r][0];
// minimize(psa[l][0] - psa[r][0] + psa[r][1] - psa[l][1])
// mi = psa[l][0] - psa[l][1]
// add = psa[r][1] - psa[r][0]
int main()
{
    cin>>T;
    while(T--){
        // 1 = R, 0 = W
        cin>>N>>str; ms(psa, 0); mi = 1e9, res = 1e9;
        for(int i = 1; i <= N; ++i){
            if(str[i-1]=='R') ++psa[i][1];
            else ++psa[i][0];
            psa[i][0] += psa[i-1][0]; psa[i][1] += psa[i-1][1];
        }
        mi = psa[1][0] - psa[1][1];
        for(int i = 2; i < N; ++i){
            res = min(res, psa[i][1] - psa[i][0] + mi);
            mi = min(mi, psa[i][0] - psa[i][1]);
        }
        cout<<res+psa[N][0]<<endl;
    }
    return 0;
}