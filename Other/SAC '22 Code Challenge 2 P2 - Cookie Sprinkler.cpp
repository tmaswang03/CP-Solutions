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
const ll MM = 510;
using namespace std;
int N, Q, cookie[MM][MM], a[MM][MM], x, y, x2, y2, opt, cnt;
int main()
{
    boost();
    cin>>N>>Q;
    while(Q--) {
        cin>>opt;
        if(opt == 1) {
            cin>>x>>y; ++a[x][y];
        }
        else {
            cin>>x>>y>>x2>>y2;
            for(int i = x; i <= x2; ++i) {
                for(int j = y; j <= y2; ++j) cnt += a[i][j];
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}