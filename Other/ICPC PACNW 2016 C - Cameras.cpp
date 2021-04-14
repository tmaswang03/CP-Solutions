#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{
    int N; gc(N);
    bool arr[N];
    ms(arr,false);
    int k, r; gc(k); gc(r);
    for(int i = 0; i < k; ++i){
        int p; gc(p);
        arr[p]=true;
    }
    int p1 = 0; p2 = r;
    int nocam=0, cam = 0, counter = 0;
    for(int i = 0; i < r; ++i){
        if(arr[N]){
            ++cam;
        }else{
            ++nocam;
        }
    } //sliding window too lazy to implement lol
    while(p2!=N){
        if(cam==0){
            ++counter;
            arr[p2]=1;
        }
      if(arr[p1]){
        --nocam;
      }
      if()
    }
    return 0;
}
