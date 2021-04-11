#include <iostream>

using namespace std;

int main()
{
    int N, K; cin>>N>>K;
    int j = 0;
    while(j*K<=N){
        j++;
    }
    int mul1=j*K;
    int mul2=(j-1)*K;
    int diff1=mul1-N;
    int diff2=N-mul2;
    if(j==1){
        cout<<diff1<<endl;
    }
    else if(diff1<=diff2){
        cout<<diff1<<endl;
    }
    else{
        cout<<diff2<<endl;
    }
    return 0;
}
