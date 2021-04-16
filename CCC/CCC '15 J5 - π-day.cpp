#include <iostream>
#include <cstring>
using namespace std;

int dp[251][251];
int pie(int n, int k){
    if(dp[n][k]==-1){
        if(n<k){
            dp[n][k]=0;
        }
        else if(n==k||k==1){
            dp[n][k]=1;
        }
        else{
            dp[n][k]=(pie(n-1,k-1)+pie(n-k,k));
        }
    }
    return dp[n][k];
}

int main() {
    memset(dp,-1,sizeof(dp));
  int n,k;cin>>n>>k;
  cout<<pie(n,k)<<endl;
  return 0;
}
