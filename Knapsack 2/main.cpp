#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

pair<int,int>arr[101];
long long knapsack(long long N, long long w){
    if(N==0 && w==0){
        return 0;
    }
        if(N-1>=0){
            if(w-arr[N].first<0){
                return knapsack(N-1,w);
            }
            else{
                return max(knapsack(N-1,w),knapsack(N-1,w-arr[N].first)+arr[N].second);
            }
        }
        else{
            return 0;
        }


}


int main()
{
    int N,total; gc(N);gc(total);
    for(int i = 1; i <= N; ++i){
        int a,p; gc(a); gc(p);
        arr[i].first=a;
        arr[i].second=p;
    }

    printf("%lld\n",knapsack(N,total));

    return 0;
}
