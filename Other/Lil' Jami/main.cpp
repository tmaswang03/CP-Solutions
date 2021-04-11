#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10;
using namespace std;
int N, K, k, Q, a, b, psa[MM];
int main()
{
    scana(N, K);
    for(int i = 0; i < K; ++i){
        scan(k); ++psa[k];
    }
    for(int i = 1; i <= N; ++i) psa[i]+=psa[i-1];
    scan(Q);
    while(Q--){
        scana(a, b);
        printf("%d\n", psa[b]-psa[a-1]);
    }
    return 0;
}
