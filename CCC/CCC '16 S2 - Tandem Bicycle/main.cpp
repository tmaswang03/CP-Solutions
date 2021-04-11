#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int intq; cin>>intq;
  int N; cin>>N;
  vector<int>arr1;
  vector<int>arr2;
  int total=0;
  arr1.resize(N);
  arr2.resize(N);
  for(int i = 0 ; i < N; i++){
    int c; cin>>c;
    arr1[i]=c;
  }
  for(int i = 0 ; i < N; i++){
    int c; cin>>c;
    arr2[i]=c;
  }

  if(intq==1){
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(int j = 0 ; j < N; j++){
        total+=max(arr1[j],arr2[j]);
    }
  }
  else{
    sort(arr1.rbegin(),arr1.rend());
    sort(arr2.begin(),arr2.end());
    for(int j = 0 ; j < N; j++){
        total+=max(arr1[j],arr2[j]);
    }
  }
  cout<<total;

  return 0;
}
