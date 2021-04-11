#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int arr[101];
    for(int i = 0; i < n; ++i){
        int a; cin>>a;
        arr[i]=a;
    }
    int counter = 1;
    int tempcounter =1;
    for(int i = 1; i < n; ++i){
         if(abs(arr[i]-arr[i-1])<=2){
            tempcounter++;
         }else{
            counter = max(counter,tempcounter);
            tempcounter = 1;
         }
    }
    counter = max(counter,tempcounter);
    cout<<counter<<endl;
    return 0;
}
