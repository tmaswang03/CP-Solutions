#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
char _;
typedef  unsigned long long ull;
typedef long long ll;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f;
#define pb push_back
using namespace std;

int main()
{
    int T; scan(T);
    for(int i = 0; i < T; ++i){
        int s,f,temp1,temp2; scan(s); scan(f);
        if(s%4==0)temp1 = 1;
        else if (s%4==3)temp1 = s-1;
        else if (s%4==2)temp1 = 0;
        else temp1 =s;
        if(f%4==3)temp2 = 1;
        else if (f%4==2)temp2 = f;
        else if (f%4==1)temp2 = 0;
        else temp2 =f+1;
        cout<<(int)(temp2^temp1)<<endl;
    }
    return 0;
}
