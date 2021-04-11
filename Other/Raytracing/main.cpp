#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;

using namespace std;


int arr[8193];

int main()
{
    int N; gc(N);
    for(int i = 0; i < N; ++i){
        int h; gc(h);
        arr[i]=h;
    }


    int C; gc(C);
    for(int i = 0; i < C; ++i){
        int a; gc(a);
        if(a==1){
            int h,j,k,l;
            gc(h);gc(j);gc(k);gc(l);
            int counter=0;
            for(int i = h; i<=j; ++i){
                if(arr[i]>=k&&arr[i]<=l){
                    ++counter;
                }
            }
            printf("%i\n",counter);
        }
        else{
            int i,h; gc(i); gc(h);
            arr[i]=h;
        }
    }

    return 0;
}
