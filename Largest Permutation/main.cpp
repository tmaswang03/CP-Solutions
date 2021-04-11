#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areEqual(vector<int>arr1, vector<int>arr2,int n)
{
    for (int i = 0; i < n; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k; cin>>n>>k;
    vector <int> arr1;
    arr1.resize(n);
    for(int i = 0 ; i < n; i++){
        int a; cin>>a;
        arr1[i]=a;
    }
    vector <int> arr2 = arr1;
    sort(arr2.rbegin(),arr2.rend());
    int counter=0;
    while(counter<k){
        for (int i = 0 ; i < k; i++){
            for(int j = 0 ; j < n; j++){
                if(arr2[i]==arr1[j]&&i!=j){
                    int a = arr1[i];
                    int b = arr2[i];
                    arr1[i]=b;
                    arr1[j]=a;
                    ++counter;
                    if(areEqual(arr1,arr2,n)==true){
                        for(int i = 0 ; i < n; i++){
                            cout<<arr1[i]<<" ";
                        }
                        exit(0);
                    }
                    break;;
                }
                else if(arr2[i]==arr1[j]&&i==j){
                    ++i;
                }
            }
        }
}
    for(int i = 0 ; i < n; i++){
        cout<<arr1[i]<<" ";
    }

    return 0;
}
