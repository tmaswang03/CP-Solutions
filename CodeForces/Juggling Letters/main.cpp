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
const ll MM = 1e3+10;
using namespace std;
int freq[26];
int main()
{
    int t; scan(t);
    while(t--){
        ms(freq, 0);
        int a, res; scan(a); bool ispos = 1;
        for(int i = 0;  i < a; ++i){
            string s; cin>>s;
            for(int j = 0; j < s.length(); ++j){
                ++freq[s[j]-'a'];
            }
        }
        for(int i = 0; i < 26; ++i){
            if(freq[i]%a) ispos = 0;
        }
        printf(ispos ? "YES\n" : "NO\n");
    }
    return 0;
}
