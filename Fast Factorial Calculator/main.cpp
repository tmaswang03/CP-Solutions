#include <iostream>
#include <math.h>
using namespace std;

long factorials[33]={0};
long factorial (int n){
    factorials[0]=1;
    for(long i = 1; i<=n; i++){
      if(i*factorials[i-1]>4294967296){
        factorials[i]=long(i*factorials[i-1])%4294967296;
      }
      else{
        factorials[i]=i*factorials[i-1];
      }
    }
    return factorials[n];
}


int main() {
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        unsigned long long a; cin>>a;
        if (a>=34){
            cout<<0<<endl;
        }
        else{
          cout<<factorial(a)<<endl;
        }

    }
  return 0;
}
