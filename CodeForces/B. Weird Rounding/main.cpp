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
int k, cnt = 0, zer = 0;
string s;
int main()
{
    cin>>s>>k;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); ++i){
        if(s[i]=='0')++zer;
    }
    if(zer < k && zer){ cout<<s.length()-1<<endl; return 0;}
    else if(zer < k){cout<<s.length()<<endl; return 0;}
    for(int i = 0; i < k; ++i){
        if(s[i]!='0'){++cnt; ++k;}
    }
    cout<<cnt<<endl;
    return 0;
}
