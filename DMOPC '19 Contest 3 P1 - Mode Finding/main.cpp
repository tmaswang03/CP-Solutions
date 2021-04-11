#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
using namespace std;

int main()
{
    int n; cin>>n;
    map<int, int> m;
    for(int i = 0; i < n; ++i){
        int l; cin>>l;
        ++m[l];
    }
    int max1 = 0;
    vector<int>v;
    for(auto && i : m){
        if(i.second>max1){
            max1=i.second;
            v.clear();
            v.push_back(i.first);
        }
        else if(i.second==max1){
            v.push_back(i.first);
        }
    }
    sort(v.begin(),v.end());
    for(auto && i : v){
        cout<<i<<" ";
    }
    return 0;
}
