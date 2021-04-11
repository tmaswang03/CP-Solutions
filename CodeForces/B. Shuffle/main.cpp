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
int t, n, m, x, y, l, r;
int main()
{
    // idea, only keep track of the range that's possible
    cin>>t;
    while(t--){
        cin>>n>>x>>m;
        l =  x; r = x;
        for(int i = 0; i < m; ++i){
            cin>>x>>y;
            if(l<= y && r >= x){
                l = min(x, l); r = max(r, y);
            }
        }
        cout<<r-l+1<<endl;
    }
    return 0;
}
