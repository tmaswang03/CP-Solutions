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
using namespace std;
ll t, a, b;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        // find if there exists a point in which
        // a - 3n = 2(b - 3n)
        // a - 3n  = 2b - 6n
        // a + 3n = 2b;
        // 2b - a = 3n, 3n <= b;
        if(a < b) swap(a, b);
        if( (2*b - a)%3 == 0 && 2*b - a >= 0 && 2*b - a <= b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
