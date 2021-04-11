#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
const ll INF = LLONG_MAX;
using namespace std;

int arr[3000];
ll interval[3000][3000];
ll dp (int a, int b){
    if(interval[a][b]!=INF){
        if(a>b){
            interval[a][b]=INF;
        }
        else if (a==b){
            interval[a][b]=arr[a];
        }
        else if(b-a==1){
            interval[a][b]=max(arr[a],arr[b])-min(arr[a],arr[b]);
        }
        else{
            interval[a][b]=max(dp(a,a)-dp(a+1,b),dp(b,b)-dp(a,b-1));
        }
    }
    return interval[a][b];
}

int main()
{
    ms(interval,INF);
    int N; gc(N);
    for(int i = 0; i < N; ++i){
        int a; gc(a); arr[i]=a;
    }
    for(int L = N-1; L >= 0; --L){
        for(int R = L; R<=N-1; ++R ){
            if(R==L){
                interval[L][R]=arr[R];
            }
            else{
            interval[L][R]=max(arr[L]-interval[L+1][R],arr[R]-interval[L][R-1]);
            }
        }
    }
    printf("%lld\n",interval[0][N-1]);

    return 0;
}
