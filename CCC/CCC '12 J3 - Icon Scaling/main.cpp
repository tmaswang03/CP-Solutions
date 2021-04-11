#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;
    char str1[3]={'*','x','*'};
    char str2[3]={' ','x','x'};
    char str3[3]={'*',' ','*'};

    for(int x = 0; x < k; ++x){
        for(int i = 0 ; i < 3; ++i){
            for(int j = 0 ; j < k; ++j){
                cout<<str1[i]<<"";
            }
        }
    cout<<endl;
    }
    for(int x = 0; x < k; ++x){
        for(int i = 0 ; i < 3; ++i){
            for(int j = 0 ; j < k; ++j){
                cout<<str2[i]<<"";
            }
        }
    cout<<endl;
    }

    for(int x = 0; x < k; ++x){
        for(int i = 0 ; i < 3; ++i){
            for(int j = 0 ; j < k; ++j){
                cout<<str3[i]<<"";
            }
        }
    cout<<endl;
    }
    return 0;
}
