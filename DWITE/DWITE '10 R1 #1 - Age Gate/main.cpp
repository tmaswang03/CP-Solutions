#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef  unsigned long long ull;
typedef long long ll;
using namespace std;

int main()
{
    for(int i = 0; i < 5; ++i){
        // cur date is 27,10,2010; >13
        int d,m,y; scan(d); scan(m); scan(y);
        bool isyoung = 0;
        if(y<2010-13) isyoung = 1;
        else{
            if(y==2010-13 && m < 10) isyoung = 1;
            else if(y==2010-13 && m == 10 && d <=27) isyoung = 1;
        }
        if(isyoung) cout<<"old enough"<<endl;
        else cout<<"too young"<<endl;
    }
    return 0;
}
