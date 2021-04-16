#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin>>N;
    long long arr[101];
    for(int i = 0; i < N; ++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    long double mins = 0x3f3f3f3f;
    for(int i = 1; i < N-1; ++i){
        long double temp = (long double)(arr[i]-arr[i-1])/(long double)(2) + (long double)(arr[i+1]-arr[i])/(long double)(2);
        mins = min(mins,temp);
    }
    cout<<fixed;
    cout<<setprecision(1);
    cout<<mins<<endl;
    return 0;
}
