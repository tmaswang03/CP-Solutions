
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <char> log;
    int N; cin >> N;
    string logstring;
    log.resize(N);
     int wholelog=0;
    int logcounter=0;
    for(int i = 0 ; i < N; i++){
        char intn;cin>>intn;
        log[i]=intn;
    }
    for(int i = 0 ; i < N; i++){
        if(log[i]=='X'&&log[i-1]!='X'&&i!=N-1&&i!=0){
            logcounter++;
        }
    }
    for(int i = 0; i < N; i++){
        if(log[i]=='X'){
            wholelog++;
        }
    }
    string logn;
    if(wholelog==N){
    cout<<0<<endl;
    }
    else{
        cout<<logcounter+1<<endl;
    }
    for(int i = 0; i<N; i++){
        if(log[i]=='O'){
            logn+='O';
        }
        if(((log[i]=='X')&&(log[i-1]!='X')&&(i!=0))||(i==N-1)){
            cout<<logn<<endl;
            logn="";
        }
    }

    return 0;
}

