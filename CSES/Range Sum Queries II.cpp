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
const ll MM = 2e5+10;
using namespace std;
ll bit[MM], a[MM], N, Q, l, r, opt;
void upd(int x, int v){for(; x < MM; x+=x&-x) bit[x] += v;}
ll query(int x){
    ll res = 0;
    for(; x > 0; x -= x&-x) res+=bit[x];
    return res;
}
int main()
{
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i){ cin>>a[i]; upd(i, a[i]);}
    while(Q--){
        cin>>opt>>l>>r;
        if(opt==1){
            ll diff = r-a[l]; a[l] = r; upd(l, diff);
        }
        else{
            cout<<query(r)-query(l-1)<<endl;
        }
    }
    return 0;
}