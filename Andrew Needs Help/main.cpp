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
const ll mod = 1e9+7;
using namespace std;
ll N, perms, res;
ll getperms(ll num){
    ll res = num;
    for(--num; num; --num){res*=num ; res%=mod;}
    return res;
}
int main()
{
    // for every pair of numbers, there are 2*p(n-2) ways
    // overlaps :
    cin>>N;
    perms = getperms(N-2);
    res = perms*N/2%mod;
    cout<<res<<endl;
    return 0;
}
