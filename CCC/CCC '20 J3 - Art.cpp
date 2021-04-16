#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll inf = 1e9;
using namespace std;
int N, bx = inf, by = inf, tx, ty, x, y;
int main()
{
    scanf("%d", &N);
    while(N--){
        scanf("%d,%d", &x, &y);
        bx = min(bx, x); by = min(by, y);
        tx = max(tx, x); ty = max(ty, y);
    }
    printf("%d,%d\n%d,%d", bx-1, by-1, tx+1, ty+1);
    return 0;
}
