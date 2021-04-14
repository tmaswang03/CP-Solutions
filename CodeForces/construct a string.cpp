#include <iostream>
using namespace std;
int main() {
  int t; cin>>t;
  for(int i = 0 ; i < t; ++i){
    int N,A,B; cin>>N>>A>>B;
    string str="";
    int j = 0;
    for(int i = 0 ; i < N; ++i){
      string strtemp;
      if(i-A<0){
        strtemp=str.substr(0, i);
      }
      else{
        strtemp=str.substr(i-A, i);
      }
      for(int i = 0; i < strtemp.length();++i){

      }
    }
    cout<<str<<endl;
  }
  return 0;
}
