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
const ll MM = 1e3+10;
using namespace std;
ll N, M, D, x, cur, res, a[MM];
int main()
{
    for(int T = 0; T < 10; ++T){
        res = 0; ms(a, 0);
        cin>>N>>M>>D; cur = N;
        for(int i = 0; i < M; ++i){
            cin>>x; ++a[x];
        }
        for(int i = 1; i <= D; ++i){
            if(!cur){
                cur = N; ++res;
            }
            if(a[i]) N+=a[i], cur+=a[i];
            --cur;
        }
        cout<<res<<endl;
    }
    return 0;
}