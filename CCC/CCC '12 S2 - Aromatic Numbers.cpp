#include <iostream>

using namespace std;

int aromatic(int a, char r){
    int vals;
    if(r=='I'){
        vals=a;
    }
    else if (r=='V'){
        vals = a*5;
    }
    else if (r=='X'){
        vals = a*10;
    }
    else if (r=='L'){
        vals = a * 50;
    }
    else if (r=='C'){
        vals = a * 100;
    }
    else if (r=='D'){
        vals = a * 500;
    }
    else {
        vals = a * 1000;
    }

    return vals;
}
int getbase(char r){
    int baseval;
    if(r=='I'){
        baseval=1;
    }
    else if (r=='V'){
        baseval=5;
    }
    else if (r=='X'){
        baseval=10;
    }
    else if (r=='L'){
        baseval=50;
    }
    else if (r=='C'){
        baseval=100;
    }
    else if (r=='D'){
        baseval=500;
    }
    else{
        baseval=1000;
    }
    return baseval;

}

int main()
{
    string aromats; cin>>aromats;
    int result=0;
    for(int i = 0 ; i < aromats.length()-2; i+=2){
        if(getbase(aromats[i+1])>=getbase(aromats[i+3])){
           result+=aromatic(int(aromats[i])-int('0'),aromats[i+1]);
           }
        else{
            result-=aromatic(int(aromats[i])-int('0'),aromats[i+1]);
        }
    }
    int i=aromats.length()-2;
    result+=aromatic(int(aromats[i])-int('0'),aromats[i+1]);
    cout<<result<<endl;
    return 0;
}
