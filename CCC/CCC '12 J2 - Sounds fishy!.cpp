#include <bits/stdc++.h>
using namespace std;
int a[4][4];
bool eq(int x, int y) {
    for(int i = 0;  i < 4; ++i){
        if(a[x][i] != a[y][i]) return 0;
        if(y <= 2 && i > 0 && a[y][i] == a[y][i-1]) return 0;
    }
    return 1;
}
int main() {
    for(int i = 0; i < 4; ++i){ cin>>a[0][i]; a[1][i] = a[0][i]; a[2][i] = a[0][i]; }
    for(int i = 0; i < 4; ++i) a[3][i] = a[0][0];
    sort(a[1], a[1]+4, greater<int>());
    sort(a[2], a[2]+4);
    if(eq(0, 1)) cout<<"Fish Diving"<<endl;
    else if(eq(0, 2)) cout<<"Fish Rising"<<endl;
    else if(eq(0, 3)) cout<<"Fish At Constant Depth"<<endl;
    else cout<<"No Fish"<<endl;

    return 0;
}