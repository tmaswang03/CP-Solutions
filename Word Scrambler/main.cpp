#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while(next_permutation(s.begin(), s.end()));
    return 0;
}
