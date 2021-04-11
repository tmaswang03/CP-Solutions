#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
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
    bool t = 1;
    for(;;){
        string s; cin>>s;
        if(s == "not") t = !t;
        else{
            if(s=="False") t = !t;
            if(t) cout<<"True"<<endl;
            else cout<<"False"<<endl;
            break;
        }
    }
    return 0;
}
