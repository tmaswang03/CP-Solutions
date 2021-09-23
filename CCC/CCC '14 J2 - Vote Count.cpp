#include <bits/stdc++.h>
using namespace std;
string str; int A, B, N; 
int main() {
    cin>>N>>str; 
    for(int i = 0; i < N; ++i) {
        if(str[i] == 'A') ++A; 
        else ++B; 
    }
    if(A>B) cout<<"A"<<endl; 
    else if(B>A) cout<<"B"<<endl; 
    else cout<<"Tie"<<endl; 
    return 0;
}