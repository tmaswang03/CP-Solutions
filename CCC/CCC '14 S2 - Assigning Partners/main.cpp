#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<string>  Array;
    vector<string>  Array1;
    int a = 0;
    cin >> a;
    Array.resize(a);
    Array1.resize(a);
    for (int i = 0; i < a; i++) {
        string b;
        cin >> b;
        Array[i] = b;
    }

    for (int i = 0; i < a; i++) {
        string c;
        cin >> c;
        Array1[i] = c;
    }
    bool isgood=true;
    //check for self pairing
    for (int i = 0; i < a; i++) {
        if (Array[i] == Array1[i]) {
            isgood=false;
        }
    }
    // if one equals one in array other equals other in array
    for (int i = 0; i <a; i++) {
        string l;
        l = Array[i];
        string r;
        r = Array1[i];
        for (int k = 0; k <a; k++) {
            if (Array[k] == r) {
                if (Array1[k] != l) {
                    isgood=false;
                }
            }
        }
    }
    if(isgood==true){
        cout<<"good"<<endl;
    }
    else{
        cout<<"bad"<<endl;
    }

    return 0;

}
