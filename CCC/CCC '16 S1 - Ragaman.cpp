#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char,int>freq;
    unordered_map<char,int>freq2;
    string s,s2;
    cin>>s>>s2;
    int wildcounter = 0;
    for(int i =0 ; i < s.length(); ++i){
        ++freq[s[i]];
    }
    for(int i =0 ; i < s2.length(); ++i){
        if(s2[i]=='*'){
            ++wildcounter;
        }
        else{
            ++freq2[s2[i]];
        }
    }
    bool extra = false;
    for(auto && i : freq){
        wildcounter-=i.second-freq2[i.first];
        if(i.second - freq2[i.first]<0){
            extra = 1;
        }
    }
    for(auto && i : freq2){
        if(!freq[i.first]){
            extra = 1;
        }
    }
    if(extra || wildcounter<0){
        cout<<"N"<<endl;
    }
    else{
        cout<<"A"<<endl;
    }

    return 0;
}
