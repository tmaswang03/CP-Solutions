#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define fscan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{
    bool arr[4][4],istree=true;int a,edgecounter=0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            fscan(a);
            if(a==1){
                ++edgecounter;
            }
            arr[i][j]=a;
        }
    }
    if(edgecounter!=6){
        istree=0;
    }
    int connectcounter;
    for(int i = 0; i < 4; ++i){
        connectcounter=0;
        for(int j = 0; j < 4; ++j){
            if(arr[i][j]){
                ++connectcounter;
            }
        }
        if(connectcounter==0){
            istree=0;
        }
    }
    printf(istree ? "Yes\n" : "No\n");
    return 0;
}
