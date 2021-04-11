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
int b[MM], N, a[MM];
bool check(int f){
    bool used[MM]; ms(a, 0); ms(used, 0);
    a[0] = f; used[f] = 1;
    for(int i = 1; i < N; ++i){
        a[i] = b[i-1]-a[i-1];
        if(a[i]<=0||a[i]>N||used[a[i]]) return 0;
        used[a[i]] = 1;
    }
    return 1;
}
int main()
{
    scan(N);
    for(int i = 0; i < N-1; ++i) scan(b[i]);
    for(int i = 1; i < b[0]; ++i){
        if(check(i)){
            for(int j = 0; j < N; ++j) cout<<a[j]<<" ";
            return 0;
        }
    }
    return 0;
}
