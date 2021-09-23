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
const ll seed = 131, mod = 1e9+7, MM = 1e6+10;
using namespace std;
ll N, p[MM], hsh[MM]; string str;
ll modd(ll in){ return (in%mod + mod)%mod; }
ll gett(int l, int r) {
    return modd (hsh[r] - hsh[l-1]*p[r-l+1]);
}
bool check (ll sz){
    if(str.length()%sz != 0) return 0;
    ll tmp = gett(1, sz);
    for(int i = 1; i < str.length()/sz; ++i){
        if(gett(i*sz+1, i*sz + sz) != tmp) return 0;
    }
    return 1;
}
int main()
{
    cin>>N; p[0] = 1;
    for(int i = 1; i < MM; ++i) p[i] = modd(p[i-1]*seed);
    while(N--){
        cin>>str; ll res = str.length();
        for(int i = 1; i <= str.length(); ++i){
            hsh[i] = modd(hsh[i-1]*seed + (str[i-1] - 'a' + 1));
        }
        for(int i = 1; i <= str.length(); ++i){
            if(check(i)) { res = i; break; }
        }
        cout<<str.length()/res<<endl;
    }
    return 0;
}