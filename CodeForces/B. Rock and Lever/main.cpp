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
const ll MM = 1e5+10;
using namespace std;
ll cnt, t, a[MM], n, freq[MM];
int lg2(int n){ return 31 - __builtin_clz(n);}
int main()
{
    // this only occurs when the highest bits are equal, sum(0 - x-1) 2^i < 2^x
    cin>>t;
    while(t--){
        cnt = 0; cin>>n; ms(freq, 0);
        for(int i = 0; i < n; ++i){ cin>>a[i]; a[i] =lg2(a[i]); }
        for(int i = 0; i < n; ++i){
            cnt+=freq[a[i]];
            ++freq[a[i]];
        }
        cout<<cnt<<endl;
    }
    return 0;
}
