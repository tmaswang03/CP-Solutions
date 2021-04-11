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
        int a, b; cin>>a>>b;
        if((a-b)%10) cout<<abs(a-b)/10+1<<endl;
        else cout<<abs(a-b)/10<<endl;
    }
    return 0;
}
