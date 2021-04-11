#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int N; cin>>N;
    vector <int> arr1;
    vector <int> arr2;
    arr1.resize(N);
    arr2.resize(N);
    int counter=1;
    int counter2=1;

    for(int i = 0; i < N; i++){
        int z;cin>>z;
        arr1[i]=z;
    }
     for(int i = 0; i < N; i++){
        int z;cin>>z;
        arr2[i]=z;
    }
    for(int i = 0 ; i < 2000000; i++){
        for(int k = 0 ; k < N; k++){
            if(arr1[k]+i==arr2[k]){
                counter++;
            }
        }
        if (counter>counter2){
            counter2=counter;
        }
        counter=0;
    }



    return 0;
}
