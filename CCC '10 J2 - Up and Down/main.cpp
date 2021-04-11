#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int a,b,c,d,s, byron = 0, nikky = 0;
int a1, b1, c1, d1;
int main()
{
    cin>>a>>b>>c>>d>>s; b1 = b; d1 = d;
    for(int i = 0; i < s; ++i){
        if(a1!=a){
            ++a1; ++nikky;
        }
        else{

        }
    }
    if(byron>nikky) cout<<"Byron"<<endl;
    else if(byron < nikky) cout<<"Nikky"<<endl;
    else cout<<"Tied"<<endl;
    return 0;
}
