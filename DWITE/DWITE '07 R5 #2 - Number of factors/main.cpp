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
    for(int i = 0; i < 5; ++i){
        int num, factorcount = 0; scan(num);
        int temp1 = num;
        for(int fac = 2; fac < num; ++fac){
            while(temp1%fac==0){
                ++factorcount;
                temp1/=fac;
            }
        }
        cout<<factorcount<<endl;
    }
    return 0;
}
