#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
      vector<int>  Array;
      int a = 0;
      cin >> a;
    Array.resize(a);
    for(int i = 0; i < a; i ++){
      int b;
      cin>>b;
      Array[i]=b;
    }

   sort(Array.begin(), Array.end());
if(a%2==0){
  for(int i = 0 ; i < a/2; i ++){
    cout<<Array[a/2-i-1]<<" "<<Array[i+a/2]<<" ";
  }
}
else{
  for(int i = 0 ; i < a/2; i ++){
    cout<<Array[a/2-i]<<" "<<Array[i+a/2+1]<<" ";
  }
  cout<<Array[0]<<endl;
}


 return 0;

}
