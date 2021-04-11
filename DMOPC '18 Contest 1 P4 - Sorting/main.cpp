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
const ll MM = 2e5+10;
using namespace std;
ll N, M, k, x, out[MM], psa[MM];
pii f[MM];
bool check(int l){
    if(psa[l+x-2]-psa[l-1]>=k) return 0;
    if(psa[l+x-1]-psa[l-1] >= k) return 1;
    return 0;
}
int main()
{
    scana(N, M, k, x); ms(out, 0); ms(psa, 0);
    for(int i = 1; i <= N; ++i){ scan(f[i].f); f[i].s = i; }
    sort(f+1, f+N+1);
    for(int i = 1; i <= N; ++i){ psa[i] = psa[i-1]+f[i].f; }
    for(int i = 1; i <= N-x+1; ++i){
        if(check(i)){
            int idx = 1;
            for(int j = 0; j < x; ++j){
                out[f[i+j].s] = j+1;
            }
            for(int j = x+1; j <= N; ++j){
                while(out[idx])++idx;
                out[idx] = j;
            }
            for(int j = 1; j <= N; ++j){
                printf("%d ", out[j]);
            }
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
