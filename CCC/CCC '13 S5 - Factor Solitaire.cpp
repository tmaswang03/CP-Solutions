#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

__attribute__ ((hot)) int biggestfact(int N){
    int factor=0;
    for(int i = 2; i <= sqrt(N); ++i){
        if(N % i == 0){
            factor = N/i;
            break;
        }
    }
    if(factor == 0){
        return 1;
    }
    return factor;

}

int main()
{
    int N; gc(N);
    int pointcounter=0;
    while(N!=1){
        int temp = biggestfact(N);
        N-=temp;
        pointcounter+=N/temp;
    }
    printf("%i\n",pointcounter);
    return 0;
}
