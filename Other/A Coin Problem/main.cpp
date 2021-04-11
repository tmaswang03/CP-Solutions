#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;

using namespace std;

bool myComparison(const tuple<int,int,int> &a,const tuple<int,int,int> &b)
{
       return get<0>(a) < get<0>(b);
}


int dp[10000];
int main()
{
    int arr[2001];
    tuple<int, int, int>tl[100001];
    int N,V; gc(N); gc(V);
    for(int i = 0; i < N; ++i){
        int a; gc(a);
        arr[i]=a;
    }
    int output[100001];
    int max1=0;
    for(int i = 0; i < V; ++i){
        int a, b; gc(a); gc(b);
        if(a>max1){
            max1=a;
        }
        tl[i]={b,a,i};
    }
    sort(tl,tl+V,myComparison);
    ms(dp,0x3f3f3f);
    dp[0]=0;
    int temp=0;

    for(int j=0; j < N; ++j){
        for(int i = arr[j]; i <= max1; ++i){
                dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
            while(get<0>(tl[temp])==j+1){
                output[get<2>(tl[temp])]=dp[get<1>(tl[temp])];
                ++temp;
            }

        }
    for(int j = 0; j < V; ++j){
        printf(output[j]>=0x3f3f3f ? "-1\n" : "%i\n",output[j]);
    }
    return 0;
}
