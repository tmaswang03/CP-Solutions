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
int N, a[2][MM], b[MM], ma = 0;
int check(int cur){
    int cnt = 0;
    for(int i = 0; i < N;  ++i){
        if(a[cur%2][i]==b[i]) ++cnt;
    }
    return cnt;
}
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i) scan(a[1][i]);
    for(int i = 0; i < N; ++i) scan(b[i]);
    for(int i = 0;  i < N; ++i){
        for(int j = 0; j < N; ++j){
            a[i%2][(j+1)%N] = a[(i%2+1)%2][j];
        }
        ma = max(ma, check(i));
    }
    printf("%d\n", ma);
    return 0;
}
