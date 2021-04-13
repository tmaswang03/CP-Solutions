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
const ll MM = 2e3+10;
using namespace std;
ll a[MM], N, res = 0, num, tmp[MM], cur;
ll solve(ll x){
    ll mi = 0;
    for(int i = 0; i < N; ++i){
        tmp[i] = 1LL*a[i]^x;
    }
    sort(tmp, tmp+N);
    for(int i = 0; i < N; ++i){
        if(tmp[i]==mi) ++mi;
    }
    return mi;
}
int main()
{
    // you need a 0 so, all numbers xor eq to 0
    cin>>N;
    for(int i = 0; i < N; ++i) cin>>a[i];
    for(int i = 0; i < N; ++i){
        ll cur = solve(a[i]);
        if(cur>res){
            res = cur; num = a[i];
        }
        else if(cur==res){
            num = min(num, a[i]);
        }
    }
    cout<<res<<" "<<num<<endl;
    return 0;
}
