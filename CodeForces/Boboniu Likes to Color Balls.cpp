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
using namespace std;
ll a[5];
int main()
{
    int T; scan(T);
    for(int i = 0; i < T; ++i){
        ll minballs = 0x3f3f3f3f, ecnt = 0, ocnt = 0, zcnt = 0;
        bool istrue = 0;
        for(int b = 0; b < 3; ++b){
            scan(a[b]);
            if(a[b] == 0) ++zcnt;
            else if(a[b]%2==0) ++ecnt;
            else ++ocnt;
            minballs = min(minballs, a[b]);
        }
        scan(a[3]);
        if(a[3] == 0) ++zcnt;
        else if(a[3]%2==0) ++ecnt;
        else ++ocnt;
        if( (ocnt >= 3-zcnt && !zcnt)|| ecnt >= 3-zcnt || (ocnt <= 1)) istrue = 1;
        ecnt = zcnt = ocnt = 0;
        for(int b = 0; b < 3; ++b){
            a[b]-=minballs;
            if(a[b] == 0) ++zcnt;
            else if(a[b]%2==0) ++ecnt;
            else ++ocnt;
        }
        a[3]+=minballs;
        if(a[3] == 0) ++zcnt;
        else if(a[3]%2==0) ++ecnt;
        else ++ocnt;
        if(  (ocnt >= 3-zcnt && !zcnt)|| ecnt >= 3-zcnt || (ocnt <= 1)) istrue = 1;
        if(istrue) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
