#include <iostream>

using namespace std;

int main()
{
    int arr[2][2]={1,2,3,4};
    string s; cin>>s;
    for(int i = 0; i < s.length(); ++i){
        if(s[i]=='V'){
            swap(arr[0][0],arr[0][1]);
            swap(arr[1][0],arr[1][1]);
        }
        else{
            swap(arr[0][0],arr[1][0]);
            swap(arr[0][1],arr[1][1]);
        }
    }
    for(int i = 0; i < 2; ++i){
        cout<<arr[0][i]<<" ";
    }cout<<endl;
    for(int i = 0; i < 2; ++i){
        cout<<arr[1][i]<<" ";
    }cout<<endl;
    return 0;
}
