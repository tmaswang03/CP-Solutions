#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
const ll INF = -500000000;
using namespace std;

int arr[3000];
ll interval[3000][3000];
ll dp (int a, int b){
    if(interval[a][b]==0){
        if (a==b){
            interval[a][b]=arr[a];
        }
        else{
            interval[a][b]=max(dp(a,a)-dp(a+1,b),dp(b,b)-dp(a,b-1));
        }
    }
    return interval[a][b];
}

int main()
{
    ms(interval,0);
    int N; gc(N);
    for(int i = 0; i < N; ++i){
        int a; gc(a); arr[i]=a;

    }
    printf("%lld\n",dp(0,N-1));

    return 0;
}
