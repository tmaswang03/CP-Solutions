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
const ll MM = 1e5+10;
using namespace std;
ll n, d, a[MM], pt = 0, res = 0;
ll calc(ll n){return (n*(n+1))/2;}
int main()
{
    cin>>n>>d;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    sort(a, a+n);
    for(int i = 2; i < n; ++i){
        while(a[i]-a[pt]>d) ++pt;
        if(a[pt]!=a[i]){
            res+=calc(i-pt-1);
        }
    }
    cout<<res<<endl;
    return 0;
}
