#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    for(int i = 0; i < 10; ++i){
        int N, counter = 0; scan(N);
        unordered_map<string,bool>umap;
        for(int k = 0; k < N; ++k){
            string str, tempstr = ""; cin>>str;
            bool at1 = false;
            for(int it = 0; it < str.length(); ++it){
                if(str[it]!='.' && str[it]!='+'){
                    tempstr+=tolower(str[it]);
                    if(str[it]=='@') at1 = 1;
                }
                else if (str[it]=='+'){
                    while(str[it]!='@' && it < str.length()) ++it;
                    --it;
                }
                else if (str[it]=='.' && at1){
                    tempstr+=str[it];
                }
            }
            if(!umap[tempstr]) umap[tempstr] = 1;
        }
        for(auto && it: umap) ++counter;
        cout<<counter<<endl;
    }
    return 0;
}
