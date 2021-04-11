#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int N; cin>>N;
    int arr[N][N];
    bool isupright = true;
    for(int i = 1; i < N; ++i){
        if(arr[i][0]>arr[i-1][0]){
            isupright=false;
        }
    }
    return 0;
}
