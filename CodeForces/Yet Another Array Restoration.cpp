#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n, x, y, dif, cur, shift = 0; cin>>n>>x>>y; int i = n-1;
        // y - x = z*d where z < n find the maximum z
        for(; i >= 1; --i){
            if((y-x)%i==0) break;
        }
        dif = (y-x)/i;
        if(y-dif*(n-1)<=0){
            shift = abs(y-dif*(n-1))/dif;
            shift*=dif; shift+=dif;
        }
        cur = y+shift;
        for(int z = n; z > 0; --z){
            cout<<cur<<" "; cur-=dif;
        }cout<<endl;
    }
    return 0;
}
