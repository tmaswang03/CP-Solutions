#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
const ll MM = 2e5+10;
using namespace std;
int n, a[MM], idx[MM], res;
int main()
{
    scan(n);
    idx[0] = 1e9;
    for(int i = 1; i <= n; ++i){ scan(a[i]); idx[a[i]] = i; }
    for(int i = 1; i <= n; ++i) if(idx[i-1]>idx[i]) ++res;
    printf("%d\n", res);
    return 0;
}
