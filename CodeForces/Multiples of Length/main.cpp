#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
ll a[MM];
int main()
{
    // take length n-1 and then  increase all of them by their own value
    boost();
    ll n; cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
    }
    if(n==1){
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<-a[1]<<endl;
        return 0;
    }
    cout<<1<<" "<<n-1<<endl;
    for(int i = 1; i < n; ++i){
        cout<<(n-1)*a[i]<<" ";
        a[i]+=(n-1)*a[i];
    }cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<-a[n]<<endl;
    a[n] = 0;
    cout<<1<<" "<<n<<endl;
    for(int i = 1; i <= n; ++i){
        cout<<-a[i]<<" ";
    }
    return 0;
}
