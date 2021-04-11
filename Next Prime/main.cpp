#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


unsigned long long  modulo(unsigned long long  base, unsigned long long p)
{
    unsigned long long exp = p-1;
    unsigned long long x = 1;
    unsigned long long y = base;
    while (exp > 0)
        {
            if (exp % 2 == 1)
                x = (x * y) % p;
            y = (y * y) % p;
            exp/=2;
        }
    return x % p;
}

bool fermatprimtest(unsigned long long n){
    if(n==1||n==4||n==6||n==8||n==9){
        return false;
    }
    for(int i = 0; i < min(n,(unsigned long long )10000); ++i){
        unsigned long long x =2+ rand()%n-4;
        if(modulo(x,n)!=1){
            return false;
        }
    }
    return true;

}

int main()
{
    unsigned long long N; cin>>N;
    if(N<=2){
        cout<<2<<endl;
            exit(0);
    }
    if (N%2==0){
        ++N;
    }
    unsigned long long i = N;
    while(fermatprimtest(i)==false){
        i+=2;
    }
    cout<<i<<endl;
    return 0;
}
