#include <iostream>
#include <vector>
using namespace std;
    int casevalue(int int1){
        int value;
        if(int1==1){
            value=100;
        }
        else if(int1==2){
            value=500;
        }
        else if(int1==3){
            value=1000;
        }
        else if (int1==4){
            value=5000;
        }
        else if(int1==5){
            value=10000;
        }
        else if(int1==6){
            value=25000;
        }
        else if(int1==7){
            value=50000;
        }
        else if(int1==8){
            value=100000;
        }
        else if(int1==9){
                value=500000;
        }
        else {
            value=1000000;
        }
        return value;
    }
int main()
{
    int n; cin>>n;
    int inttotal;
    inttotal=1691600;
    for(int i = 0 ; i < n; i++){
        int int1; cin>>int1;
        inttotal=inttotal-casevalue(int1);
    }
    int bankercase; cin>>bankercase;
    if(bankercase>inttotal/(10-n)){
        cout<<"deal"<<endl;
    }
    else{
        cout<<"no deal"<<endl;
    }
    return 0;
}
