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
const ll MN = 1e9;
using namespace std;
int T, cur;
int main()
{
    scan(T);
    while(T--){
        string s = "";
        scan(cur); bool fst = 0;
        for(int i = 1; i <= cur; i<<=1){
            s+=(bool)(i&cur)+'0';
        }
        while(s.length()%4) s+='0';
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.length(); ++i){
            cout<<s[i];
            if((i+1)%4==0)cout<<" ";
        }
        if(cur==0) cout<<"0000";
        cout<<endl;
    }
    return 0;
}
