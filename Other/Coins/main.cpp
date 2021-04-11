#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long double dl;
using namespace std;

dl arr[3000];
dl dp[3000][3000];
dl headsprob(int tosses, int heads){
    if(tosses<0||heads<0){
        return 0;
    }
    else if(dp[tosses][heads]!=-1){
        return dp[tosses][heads];
    }
    else{
        if(heads>tosses){
            dp[tosses][heads]=0;
        }
        else{
            dp[tosses][heads]=headsprob(tosses-1,heads-1)*(arr[tosses]);
            dp[tosses][heads]+=headsprob(tosses-1,heads)*((dl)1-arr[tosses]);
        }
        return dp[tosses][heads];
    }
}

int main()
{
    ms(dp,-1);
    dp[0][0]=1;
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        dl a; cin>>a;
        arr[i+1]=a;
    }
    dl const1=0;
    for(int i = n/2+1; i<=n; ++i){
        const1+=headsprob(n,i);
    }

    cout<<setprecision(16)<<const1<<"\n";
    return 0;
}
