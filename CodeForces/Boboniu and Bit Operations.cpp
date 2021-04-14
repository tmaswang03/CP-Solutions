#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 200;
using namespace std;
int a[MM], b[MM], c[MM];
int main()
{
    int n, m, ans = 0x3f3f3f3f; scan(n); scan(m);
    for(int i = 0; i < n; ++i){
        scan(a[i]);
    }
    for(int i = 0; i < m; ++i){
        scan(b[i]);
    }
    for(int or1 = 0; or1 < 1<<9; ++or1){
        bool pos = 1;
        for(int i = 0; i < n; ++i){
            bool pos1 = 0;
            for(int j = 0; j < m; ++j){
                if((int)((a[i]&b[j])|or1)==or1){
                    pos1 = 1;
                    break;
                }
            }
            if(!pos1){
                pos = 0; break;
            }
        }
        if(pos){ printf("%d\n", or1); return 0;}
    }
    return 0;
}
