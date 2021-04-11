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
const ll MM = 3e5+10;
using namespace std;
int a[MM];
int main()
{
    int len; cin>>len;
    string s; cin>>s;
    a[len] = 0x3f3f3f;
    for(int i = len-1; i >= 0; --i){
        a[i] = min(a[i+1], (int)(s[i]));
    }
    for(int i = 0; i < len; ++i){
        if(a[i]<s[i]){
            cout<<"YES"<<endl;
            int j = i+1;
            for(; j < len; ++j) if(s[j]<s[i]) break;
            cout<<i+1<<" "<<j+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
