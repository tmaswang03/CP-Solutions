#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin>>N;
    int pfsum1[N+1];
    int pfsum2[N+1];
    pfsum1[0]=pfsum2[0]=0;
    for(int i = 1; i <= N; ++i){
        int a; cin>>a;
        pfsum1[i]=pfsum1[i-1]+a;
    }
    for(int i = 1; i <= N; ++i){
        int a; cin>>a;
        pfsum2[i]=pfsum2[i-1]+a;
    }
    int counter = 0;
    for(int i = 1; i <= N; ++i){
        if(pfsum1[i]==pfsum2[i]){
            counter = i;
        }
    }
    cout<<counter<<endl;
    return 0;
}
