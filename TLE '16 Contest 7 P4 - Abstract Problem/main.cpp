#include<bits/stdc++.h>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
typedef long long ll;

//Given an integer x you want to change 0 into that number using a minimal number of the following operations:
//
//Add 1
//Subtract 1
//Multiply by 2


//x = even x/=2
// x % 4 == 1 minus 1
// x % 4 == 3 add 1
// exception = 3
int main()
{
    ll N; gc(N);
    for(int i = 0; i < N; ++i){
        long x; gc(x);
        long counter = 0;
        while(x!=0){
            if(x==3){
                counter+=3;
                break;;
            }
            if(x%4==1){
                x-=1;
            }
            else if( x%4==3){
                x+=1;
            }
            else{
                x/=2;
            }
            ++counter;
        }printf("%llu\n",counter);
    }

    return 0;
}
