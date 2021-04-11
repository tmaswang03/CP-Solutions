#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    long saws[50000], logs[50000];
    for(int i = 0 ; i < n; ++i){
        int a; cin>>a;
        saws[i]=a;
    }
    for(int i = 0 ; i < n; ++i){
        int a; cin>>a;
        logs[i]=a;
    }
    sort(saws,saws+n);
    sort(logs, logs+n, greater<long>());
    int total=0;
    for(int i = 0 ; i < n; i++){
        total+=(long)(logs[i]*saws[i]);
    }
    cout<<total<<endl;
    return 0;
}
