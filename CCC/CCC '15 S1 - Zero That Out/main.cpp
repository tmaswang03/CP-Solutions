#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int N; cin>>N;
    for(int i = 0; i < N; ++i){
        int a; cin>>a;
        if(a!=0){
            s.push(a);
        }
        else{
            s.pop();
        }
    }
    int total = 0;
    while(!s.empty()){
        total+=s.top();
        s.pop();
    }
    cout<<total<<endl;
    return 0;
}
