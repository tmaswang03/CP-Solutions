#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
typedef long long ll;
char _;
using namespace std;

ll dp[31];

ll tiles (int a){
    if(dp[a]!=-1){
        return dp[a];
    }
    else{
        dp[a]=0;
        dp[a]=dp[2]*tiles(a-2);
        for(int j = i-4; j >=0; j-=2){
            dp[a]+=2*tiles(j);
            dp[a]%=1000000;
        }
        dp[a]%=1000000;
        return dp[a];
    }


}


int main()
{
    ms(dp,-1);
    dp[0]=1;
    dp[2]=3;
    dp[4]=11;
    for(int i = 0; i < 5; ++i){
        int a; cin>>a;
        if(a&1){
            dp[a]=0;
            cout<<dp[a]<<endl;
        }
        else{
            cout<<tiles(a)<<endl;
        }
    }
    return 0;
}
