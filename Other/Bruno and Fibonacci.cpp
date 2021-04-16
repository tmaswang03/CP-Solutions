// Bruno and fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int arr1[13] = { 0, 1, 2, 4, 7, 12, 20, 33, 54, 88, 143, 232, 376 };
    int a; cin >> a;
    string act;
    cin >> act;
    for (int i = 0; i < a; i++) {
        if(act[i] == 'A') {
            if (i != 0 && i != 1 && i != 2 && i != 4 && i != 7 && i != 12 && i != 20 && i != 33 && i != 54&& i != 88 && i != 143 && i != 232 && i != 376) {
                cout <<"Bruno, GO TO SLEEP"<< endl;
                exit(0);
            }
    }
    }
       for (int i = 0; arr1[i] < a; i++) {
        if (act[arr1[i]] != 'A') {
            cout << "Bruno, GO TO SLEEP"<<endl;
            exit(0);
        }
    }



    cout << "That's quite the observation!" << endl;

    return 0;
}

