#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;
int main()
{
    int h, m; cin >> h >> m;
    int alt;
    for (int i = 1; i < m; i++) {
        alt = -6 * pow(i, 4) + h * pow(i, 3) + 2 * pow(i, 2) + i;
        if (alt <= 0) {
            cout << "The balloon first touches ground at hour:\n"<<i<< endl;
            exit(0);
        }
    }
    cout << "The balloon does not touch ground in the given time." << endl;
    return 0;
}
