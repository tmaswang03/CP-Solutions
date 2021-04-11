#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;

using namespace std;

int dp[100002][3];
int arr[100002][3];
int main()
{
    ms(dp,-1);
    int N; gc(N);
    for(int i = 0; i < N; ++i){
        int a,b,c; gc(a); gc(b); gc(c);
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }
    dp[0][1]=0;
    dp[0][0]=0;
    dp[0][2]=0;
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j < 3; ++j){
            dp[i+1][j]=0;
            if(j==0){
                dp[i+1][j]=max(dp[i+1][j],dp[i][1]+arr[i][0]);
                dp[i+1][j]=max(dp[i+1][j],dp[i][2]+arr[i][0]);
            }
            else if(j==1){
                dp[i+1][j]=max(dp[i+1][j],dp[i][0]+arr[i][1]);
                dp[i+1][j]=max(dp[i+1][j],dp[i][2]+arr[i][1]);
            }
            else{
                dp[i+1][j]=max(dp[i+1][j],dp[i][0]+arr[i][2]);
                dp[i+1][j]=max(dp[i+1][j],dp[i][1]+arr[i][2]);
            }
        }
    }
    int counter=0;
    for(int i = 0; i < 3; ++i){
        if(dp[N+1][i]>counter){
            counter=dp[N+1][i];
        }
    }
    printf("%i\n",counter);
    return 0;
}
