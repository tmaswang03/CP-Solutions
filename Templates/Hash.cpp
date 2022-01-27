#include<bits/stdc++.h>
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
const ll MM = 2e5+01, seed = 131, mod = 1e9+7;
using namespace std;
string str; ll p[MM], hsh[MM];
ll mmod(ll x){ return (x%mod+mod)%mod; }
ll gett(int l, int r) { return mmod(hsh[r] - hsh[l-1] * p[r - l + 1]); }
int main()
{
    // rmb to change -'A' to -'a' if lower case;
    cin>>str; p[0] = 1;
    for(int i = 1; i <= str.length(); ++i) {
        p[i] = p[i-1] * seed; hsh[i] = mmod(hsh[i-1] * seed + str[i-1] - 'A');
    }
    return 0;
}
