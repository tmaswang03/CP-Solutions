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
ll t, y, x, ro, res;
ll calc(ll in){return in*(in+1)/2;}
int main()
{
    cin>>t;
    while(t--){
        cin>>y>>x;
        ro = max(y, x);
        res = 1 + 2*calc(ro-1);
        // find the square it's on, max(y, x)
        // the value is 1 + 2*1 + 2*2 + 2*3 ...
        // if ro is odd, less y is add, else it is subtract
        if(y<ro && ro%2==0) res-=ro-y;
        else if(y<ro && ro%2==1) res+=ro-y;
        else if(x<ro && ro%2==0) res+=ro-x;
        else res-=ro-x;
        cout<<res<<endl;
    }
    return 0;
}
