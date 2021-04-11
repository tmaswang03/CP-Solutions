// C++ program to print all prime factors
#include <iostream>
#include <math.h>
#include <algorithm>
#include <array>
using namespace std;

int main(){
  unsigned long long arr[100001];
  int n; cin>>n;
  for(int i = 0 ; i < n; i++){
    long long a; cin>>a;
    arr[i]=a;
  }
  sort(arr, arr+n);
  unsigned long long temp;
  temp=arr[0];
  unsigned long long fac[100000];
  int count=0;
  if(temp%2==0){
    fac[0]=2;
    ++count;
  }
   while (temp % 2 == 0)
    {
        temp = temp/2;
    }

    for (unsigned long long i = 3; i <= sqrt(temp); i = i + 2)
    {
       if(temp%i==0){
         fac[count]=i;
         ++count;
       }
        while (temp % i == 0)
        {
            temp = temp/i;
        }
    }
    if (temp > 2){
        fac[count]=temp;
        ++count;
}
if (count==0){
  cout<<"DNE"<<endl;
  exit(0);
}
  for(long long k = count-1; k>=0; k--){
    bool isprime=true;
    for(int i = 0; i < n; i++){
      if(fac[k]==0 || arr[i]%fac[k]!=0){
        isprime=false;
        break;
      }
    }
    if(isprime==true){
      cout<<fac[k]<<endl;
      exit(0);
    }
  }
  cout<<"DNE"<<endl;
  return 0;
}
