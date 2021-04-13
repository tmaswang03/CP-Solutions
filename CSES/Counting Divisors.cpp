#include<bits/stdc++.h>
using namespace std;
int n, x, res;
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>x; res = 0;
        for(int i = 1; i*i <= x; ++i){
            if(i*i==x && x%i==0) ++res;
            else if(x%i==0) res+=2;
        }
        cout<<res<<endl;
    }
    return 0;
}
