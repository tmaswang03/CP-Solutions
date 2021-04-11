#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull modulo(ull a,ull c, ull m){
    ull b = c;
    ull x = 1;
    ull y=a%m;
    while(b > 0){
        if(b%2 == 1){
            x = (x%m*y%m)%m;
        }
        y = (y%m*y%m)%m;
        b /= 2;
    }
    return x%m;
}


int main()
{
    ull arr[2001];
    ull coeffs[2001];
    coeffs[0]=1;
    ull N,M; gc(N);
    for(ull i = 0; i < N; ++i){
        ull a; gc(a);
        arr[i]=a;
    }
    gc(M);
    for(ull i = 1; i < N; ++i){
        coeffs[i]=(coeffs[i-1]*(M+i-1)%1000000007)%1000000007;
        coeffs[i]=(coeffs[i]*(modulo(i,1000000005,1000000007)%1000000007))%1000000007;
    }

    ull outputarr[2001];

    for(ull i = 0; i < N; ++i){
        outputarr[i]=arr[i];
        for(ull j = 0; j < i; ++j){

            outputarr[i]+=(arr[j]*coeffs[i-j])%1000000007;
        }
        outputarr[i]%=1000000007;
    }
    for(ull i = 0; i < N-1; ++i){
        printf("%llu ",outputarr[i]);
    }
    printf("%llu\n",outputarr[N-1]);
    return 0;
}
