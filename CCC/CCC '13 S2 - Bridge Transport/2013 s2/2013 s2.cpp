// ccc 2013 s2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> trainarr;
    int w, n; cin >> w >> n;
    trainarr.resize(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        trainarr[i] = a;
    }
    int i = 0;
    while (trainarr[i] + trainarr[i + 1] + trainarr[i + 2] + trainarr[i + 3] < w) {
        i++;
    }
    cout << i + 5 << endl;
    return 0;
}
