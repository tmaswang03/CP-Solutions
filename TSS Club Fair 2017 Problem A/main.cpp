#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
char _;
using namespace std;

int main()
{
    int N; scan(N);
    for(int i = 0; i < N; ++i){
        unordered_map <string, int> freq;
        string s1,s2,s3; cin>>s1>>s2>>s3;
        bool ispossible = false;
        ++freq[s1]; ++freq[s2]; ++freq[s3];
        for(auto && i : freq){
            if(i.second >= 2){
                cout<<i.first<<endl;
                ispossible = 1;
                break;
            }
        }
        if(!ispossible) cout<<"???"<<endl;
    }
    return 0;
}
