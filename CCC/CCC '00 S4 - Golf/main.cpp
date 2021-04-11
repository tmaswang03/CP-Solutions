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


int dp[5281];
int main()
{
    dp[0]=0;
    int clubs[32];
    int total,clubs1; gc(total); gc(clubs1);
    for(int i = 0; i < clubs1; ++i){
        int clubdist; gc(clubdist);
        clubs[i]=clubdist;
    }

    for(int i = 1; i <= total; ++i){
        dp[i]=0x3f;
        for(int c = 0; c < clubs1; ++c){
            if(i-clubs[c]>=0){
                dp[i]=min(dp[i],dp[i-clubs[c]]+1);
            }
        }
    }


    if(dp[total]==0x3f){
        printf("Roberta acknowledges defeat.\n");
    }
    else{
        printf("Roberta wins in %i strokes.\n",dp[total]);
    }

    return 0;
}
