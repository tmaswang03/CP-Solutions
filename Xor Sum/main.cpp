#include <iostream>
#include <cstring>
using namespace std;
int main() {
  int N; cin>>N;
  int arr[100000];
  for(int i = 0; i < N; ++i){
    cin>>arr[i];
  }
  int min=0,max = 0;
  int arrtemp[100000];
    memset(arrtemp,0,sizeof(arrtemp));
  arrtemp[0]=arr[0];
  for(int i = 0 ; i < N; ++i){
    if(arrtemp[i]^=arr[i+1]<=arr[i+1]+arrtemp[i]){
      max+=arrtemp[i]; arrtemp[i+1]=arr[i+1];
    }
    else{
      arrtemp[i+1]=arrtemp[i]^=arr[i+1];
    }
    cout<<max<<" "<<arrtemp[i+1]<<endl;
  }
  memset(arrtemp,0,sizeof(arrtemp));
  arrtemp[0]=arr[0];
    for(int i = 0 ; i < N; ++i){
    if(arrtemp[i]^=arr[i+1]>arr[i+1]+arrtemp[i]){
      min+=arrtemp[i]; arrtemp[i+1]=arr[i+1];
    }
    else{
      arrtemp[i+1]=arrtemp[i]^=arr[i+1];
    }
    cout<<min<<" "<<arrtemp[i+1]<<endl;
    }
  cout<<max-min<<endl;
  return 0;
}
