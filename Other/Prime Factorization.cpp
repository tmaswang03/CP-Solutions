#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    vector <int> arr1;
    int n; cin>>n;
    arr1.resize(n);
    for(int i = 0 ; i < n; ++i){
        int a; cin>>a;
        arr1[i]=a;
    }
    for(int j = 0 ; j < n; j++){
        while(arr1[j]%2==0){
            cout<<2<<" ";
            arr1[j]=arr1[j]/2;
        }
        int i = 3;
        while(i<=sqrt(arr1[j])){
            if(arr1[j]%i==0){
                cout<<i<<" ";
                arr1[j]=arr1[j]/i;
            }
            else{
                i+=2;
            }
        }
        if(arr1[j]>2){
            cout<<arr1[j]<<"";
        }
        cout<<"\n";
    }
    return 0;
}
