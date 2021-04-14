#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
ll n, d, t;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>d; bool ye = 0;
        for(int x = 0; x <= n; ++x){
            if(x+ceil(1.0*d/(1.0*(x+1)))<= n){
                cout<<"YES"<<endl; ye = 1; break;
            }
        }
        if(!ye) cout<<"NO"<<endl;
    }
    return 0;
}
