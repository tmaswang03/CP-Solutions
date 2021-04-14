#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
const ll mod = 1e9+7;
const int max1 = 200;
using namespace std;

int arr[max1], dp[max1][max1], pfsum[max1];

int getpfsum(int l, int r){
    return pfsum[r+1]-pfsum[l];
}

int pick (int l, int r){
    if(dp[l][r]==-1){
        if(r-l<=1){
            dp[l][r]=0; return dp[l][r];
        }
        else if (r-l==2){
            dp[l][r]=getpfsum(l,r); return dp[l][r];
        }
        else{
            for(int i = l+1; i < r; ++i){
                dp[l][r]=max(dp[l][r],pick(l,i)+pick(i,r)+arr[i]);
            }dp[l][r]+=arr[l]+arr[r];
            return dp[l][r];
        }
    }
    else{
        return dp[l][r];
    }

}


int main()
{
    for(;;){
        ms(arr,0);
        ms(pfsum,0);
        ms(dp,-1);
        int n; scan(n);
        if(n==0) break;
        for(int l = 0 ; l < n; ++l){
            int t; scan(t); arr[l]=t;
            pfsum[l+1]=pfsum[l]+t;
        }
        printf("%i\n",pick(0,n-1));
    }
    return 0;
}
