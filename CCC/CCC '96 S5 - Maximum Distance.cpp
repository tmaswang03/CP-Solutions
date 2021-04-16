#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin>>n;
  for(int i = 0 ; i < n ; ++i){
    int a; cin>>a;
    vector<int>c;
    c.resize(a);
    vector <int> j;
    j.resize(a);
    int counter1 = 0;
    for(int i = 0 ; i < a; i++){
      int l; cin>>l;
      c[i]=l;
    }
    for(int i = 0 ; i < a; i++){
      int l; cin>>l;
      j[i]=l;
    }
    for(int i = 0 ; i < a; ++i){
      for(int k = 0 ; k < a; ++k){
          if(j[k]>=c[i]){
            if(k-i>counter1){
              counter1=k-i;
            }
          }
      }

    }
    cout<<"The maximum distance is "<<counter1<<endl;
  }

  return 0;
}
