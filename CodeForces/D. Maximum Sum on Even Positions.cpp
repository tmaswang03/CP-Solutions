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
const ll MM = 2e5+10;
using namespace std;
ll T, N, a[MM], psa[MM];
int main()
{
    cin>>T;
    while(T--){
        cin>>N; ll sum = 0, mio = 0, mie = 1e9, res = 0;
        for(int i = 0; i < N; ++i){
            cin>>a[i];
            if(i%2==0){
                sum+=a[i];
                psa[i] = psa[i-1]-a[i];
            }
            else psa[i] = psa[i-1]+a[i];
        }
        res = sum;
        for(int i = 0; i < N; ++i){
            if(i%2==0){
                mie = min(mie, psa[i]);
                res = max(res, sum+psa[i]-mie);
            }
            else{
                mio = min(mio, psa[i]);
                res = max(res, sum+psa[i]-mio);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
