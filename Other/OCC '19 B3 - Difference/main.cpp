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
    ll N; scan(N);
    ll temp1 = 0;
    for(int i = 1; i <= N; ++i){
        temp1 += i;
        temp1 %= 2;
    }
    if(temp1==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
