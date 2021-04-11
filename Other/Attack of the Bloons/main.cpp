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
const ll MM = 1e3+10;
using namespace std;
ll L, N, T, M, h, psa[2*MM], c, r, d;

int main()
{
    scan(T);
    while(T--){
        scan(L); scan(N); ms(psa, 0);
        for(int i = 1; i <= N; ++i){
            scana(c,r,d);
            psa[max(1LL, c-r)]+=d;
            psa[c+r+1]-=d;
        }
        for(int i = 1; i <= L; ++i) psa[i] += psa[i-1];
        for(int i = 1; i <= L; ++i) psa[i] += psa[i-1];

        scan(M);
        for(int i = 1; i <= M; ++i){
            scan(h);
            if(psa[L]<h) printf("Bloon leakage\n");
            else  printf("%d\n", lower_bound(psa+1, psa+L+1, h)-psa);
        }
    }
    return 0;
}
