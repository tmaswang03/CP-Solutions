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
int N, D, a, curs, res = 1; vector<int> s, p;
int main()
{
    scan(N); scan(D); --D;
    for(int i = 0; i < N; ++i){ scan(a); s.pb(a);} // this is points greatest to least
    for(int i = 0; i < N; ++i){ scan(a); p.pb(a);}  // rewarded for round greatest to least;
    reverse(p.begin(), p.end());
    curs=s[D]+p[N-1];
    for(int i = 0; i < N-1; ++i){
        if(s[i]+p[i]>curs) ++res;
    }
    printf("%d\n", res);
    return 0;
}
