#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
using namespace std;

int main()
{
    // flipping twice is equivalent to just flipping once
    // if there are an even number of negative numbers they can all turn positive
    // ==> sum = |atotal|
    // if there are an odd number of negative numbers we cannot turn them all positive one will be made negative
    ll N; cin>>N;
    ll negcounter=0, minnum=0x3f3f3f3f, total = 0;
    for(int i = 0; i < N; ++i){
        ll b; cin>>b;
        total+=abs(b);
        if(b<0){
            negcounter+=1;
        }
        minnum=min(abs(minnum),abs(b));
    }
    if(negcounter%2==1){//odd
        total-=2*minnum;
        printf("%lld\n",total);
    }else{
        printf("%lld\n",total);
    }
    return 0;
}
