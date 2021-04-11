#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
typedef unsigned long long ull;
const ull mod = 1000000007;



 __attribute__((hot))  void mult(ull a[2][2], ull b[2][2]){
    ull temp,temp1,temp2,temp3;
    temp = (a[0][0] * b[0][0])%mod + (a[0][1] * b[1][0])%mod;
    temp1= (a[0][0] * b[1][0])%mod + (a[1][0] * b[1][1])%mod;
    temp2 = (a[0][1] * b[0][0])%mod + (a[1][1] * b[0][1])%mod;
    temp3 = (a[0][1] * b[1][0])%mod + (a[1][1] * b[1][1])%mod;
   a[0][0] = temp%mod;
   a[1][0] = temp1%mod;
   a[0][1] = temp2%mod;
   a[1][1] = temp3%mod;

}

void pow(ull a[2][2] , ull n)
{
    ull temp[2][2];
    temp[0][0]=1;
    temp[0][1]=1;
    temp[1][0]=1;
    temp[1][1]=0;
    while(n>0){
        if(n&1==1){
            mult(temp,a);
        }
        mult(a,a);
        n=n>>1;
    }
    printf("%llu\n",temp[1][0])%mod;
}


int main()
{
    ull A[2][2];
    ull outarr[2][2];
    A[0][0]=1;
    A[0][1]=1;
    A[1][0]=1;
    A[1][1]=0;
    ull a; gc(a);
    pow (A, a-1);
    return 0;
}
