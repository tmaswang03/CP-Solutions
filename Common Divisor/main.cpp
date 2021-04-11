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
using namespace std;
vector<ll> fs; ll A, B, K;
int main()
{
    scana(A, B, K); --K;
    if(A>B) swap(A, B);
    for(ll i = 1; i*i <= A; ++i){
        if(A%i==0){
            if(B%i==0) fs.pb(i);
            if(B%(A/i)==0) fs.pb(A/i);
        }
    }
    sort(fs.begin(), fs.end(), greater<ll>());
    auto it = unique(fs.begin(), fs.end());
    fs.erase(it, fs.end());
    if(K>=fs.size()) printf("-1\n");
    else printf("%lld\n", fs[K]);
    return 0;
}
