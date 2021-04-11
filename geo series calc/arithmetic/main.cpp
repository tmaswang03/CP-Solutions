#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int arorgeo,x,a,b;
    cin>>arorgeo>>x>>a>>b;//1==arith 2==geo, x = sum of terms to calc, a = first val, b = diff/ratio
    if(arorgeo==1){
        int counter = a;
        for(int i = 1; i <= x-1; ++i){
            counter += a+i*b;
        }
        cout<<counter<<endl;
    }
    else{
        int counter = a;
        for(int i = 1; i <= x-1; ++i){
            counter += a*pow(b,i);
        }
        cout<<counter<<endl;
    }
    return 0;
}
