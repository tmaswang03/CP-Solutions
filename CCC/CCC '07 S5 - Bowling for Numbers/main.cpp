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
    int t; scan(t);
    for(int i = 0; i < t; ++i){
        int n,k,w; scan(n); scan(k); scan(w);
        int psa[n+1];
        for(int j = 0; j < n; ++j){
            scan(psa[j]); psa[j]+=psa[j-1];
        }
    }
    return 0;
}
