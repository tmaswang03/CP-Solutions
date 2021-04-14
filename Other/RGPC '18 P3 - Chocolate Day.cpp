#include <iostream>
#include <cstring>
using namespace std;

int arr[1000001];
int diffarr[1000001];
int main() {
  int N,T; cin>>N>>T;
  arr[0]=0;
  memset(diffarr,0,sizeof(diffarr));
  for(int i = 0; i < T; ++i){
    int a,b,t; cin>>a>>b>>t;
    diffarr[a]+=t;
    if(b+1<=N){
      diffarr[b+1]-=t;
    }
  }
  int L; cin>>L;
  for(int i = 1; i <=N; ++i){
    arr[i]=arr[i-1]+diffarr[i];
  }
  int counter=0;
  int l=1; int r=0;
  int total=0;
  while(l+r<=N){
      if(total+arr[l+r]<=L){
        total+=arr[l+r];
        ++r;
      }
      else{
        total-=arr[l];
        ++l; --r;
      }
      if(r>counter){
        counter=r;
      }
  }
  cout<<counter<<endl;
  return 0;
}
