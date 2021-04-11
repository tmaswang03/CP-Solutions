#include <iostream>

using namespace std;

int main()
{
    int ans=0;
    string correct;
    string student;
    int N; cin>>N;
    for(int i = 0 ; i < N; i++){
        char a;cin>>a;
        correct+=a;
    }
    for(int i = 0 ; i < N; i++){
        char a; cin>>a;
        student+=a;
    }
    for(int i = 0 ; i < N; i++){
        if(correct[i]==student[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
