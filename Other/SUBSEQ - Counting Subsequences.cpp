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
    int T; scan(T);
    for(int i = 0; i < T; ++i){
        int N; scan(N);
        int psa[N+1];
        for(int k = 1; k <= N; ++k){
            scan(psa[K]);
            psa[k]+=psa[k-1];
        }
    }
    return 0;
}
