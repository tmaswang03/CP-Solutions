#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
using namespace std;
int T, len;
string s1, s2;

int main()
{
    cin>>T;
    while(T--){
        cin>>len>>s1>>s2;
        for(int i = len-1; i >= 0; --i){
            cout<<s2[i]<<s1[i];
        }
        cout<<endl;
    }
    return 0;
}
