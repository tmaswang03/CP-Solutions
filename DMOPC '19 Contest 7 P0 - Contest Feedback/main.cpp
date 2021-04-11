#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
typedef long double ld;

int main(){
    ld a, b, c, d;
    cin>>a>>b>>c>>d;
    printf("%.6Lf\n",(a+b)/2);
    printf("%.6Lf\n",(a+c)/2);
    printf("%.6Lf\n",(a+d)/2);
    printf("%.6Lf\n",(b+c)/2);
    printf("%.6Lf\n",(b+d)/2);
    printf("%.6Lf\n",(c+d)/2);
    printf("%.6Lf\n",(a+b+c)/3);
    printf("%.6Lf\n",(a+b+d)/3);
    printf("%.6Lf\n",(a+c+d)/3);
    printf("%.6Lf\n",(b+c+d)/3);
    printf("%.6Lf\n",(a+b+c+d)/4);
    return 0;
}
