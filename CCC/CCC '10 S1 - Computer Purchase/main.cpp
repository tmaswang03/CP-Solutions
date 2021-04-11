#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin>>N;
    pair<string,int>best1,best2;
    best1 = best2 = {"",0};

    for(int i = 0; i < N; ++i){
        string s; cin>>s;
        int R,S,D; cin>>R>>S>>D;
        if(2*R+3*S+D>best1.second || (2*R+3*S+D==best1.second  && (int)s[0]<(int)best1.first[0])){
            best2 = best1;
            best1.first = s;
            best1.second = 2*R+3*S+D;
        }
        else if (2*R+3*S+D>best2.second || (2*R+3*S+D==best1.second && s>best1.first)){
            best2.second = 2*R+3*S+D;
            best2.first = s;
        }
    }
    if(best1.second != 0){
        cout<<best1.first<<endl;
    }
    if(best2.second != 0){
        cout<<best2.first<<endl;
    }
    return 0;
}
