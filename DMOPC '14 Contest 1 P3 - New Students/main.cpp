#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
int a[MM], a2[MM], N, s,res;
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
        res+=a[i];
    }
    scan(s);
    for(int i = 0; i < s; ++i){
        scan(a2[i]);
    }

    for(int k = 0; k < s; k++){
        res+=a2[k];
        float average = (float)res/(float)(N+k+1);
        printf("%lf\n", average);
    }
    return 0;
}
