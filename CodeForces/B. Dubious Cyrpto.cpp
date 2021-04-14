#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
using namespace std;
ll t, a, b, c, n, m, l, r;
int main()
{
    cin>>t;
    while(t--){
        cin>>l>>r>>m;
        // n*a + b - c = m;
        // l <= a, b, c<= r;
        // n*a = m-b+c; where n is an integer
        // b-c = m-n*a
        // search for point in which the m- (m/a)*a <= r-l;
        for(int i = l; i <= r; ++i){
            if(m - (m/i)*i <= r-l && m/i>0){
                cout<<i<<" "<<r<<" "<<r - (m-(m/i)*i) <<endl; break;
            }
            else if ( (m/i+1)*i - m <= r-l && (m/i+1)>0 ){
                cout<<i<<" "<<l<<" "<<l+(m/i+1)*i - m<<endl; break;
            }
        }
    }
    return 0;
}
