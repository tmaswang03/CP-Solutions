#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef int ll;
typedef long double ld;
const ll MAXN = 1e6+1;
using namespace std;
int arr[MAXN];

int main()
{
    int N; scan(N);
    for(int i = 0; i < N; ++i)
        scan(arr[i]);
    return 0;
}
