#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
const ll MM = 120, inf = 0x3f3f3f3f;
using namespace std;
int a[MM], freq[MM];
int main()
{
    int t; scan(t);
    while(t--){
        ms(freq, 0);
        int N, res = 0; scan(N);
        for(int i = 0; i < N; ++i){
            scan(a[i]); ++freq[a[i]];
        }
        for(int sum = 0; sum <= 110; ++sum){
            int cur = 0;
            for(int i = 0; i <= sum; ++i){
                cur+= min(freq[i], freq[sum-i]);
            }
            res = max(res, cur>>1);
        }
        printf("%d\n", res);
    }
    return 0;
}
