#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 5e5+10;
using namespace std;
int N, Q, tot, psa[MM];
int main()
{
    scan(N); scan(Q);
    for(int i = 1 ; i <= N; ++i){
        scan(psa[i]); tot+=psa[i];
        psa[i] += psa[i-1];
    }
    while(Q--){
        int a, b; scan(a); scan(b);
        printf("%d\n", tot - psa[b]+psa[a-1]);
    }
    return 0;
}
