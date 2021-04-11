#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
int main()
{
    int N, K; scan(N); scan(K);
    int a[N+1], b[N+1], diffs[N+1];
    for(int i = 0; i < N; ++i)
        scan(a+i);
    for(int i = 0; i < N; ++i)
        scan(b+i);
    for(int i = 0; i < N; ++i)
        diffs[i] = a[i]-b[i];
    int median =
    return 0;
}
