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
const ll MM = 150010;
using namespace std;
ll a[MM], psa[MM], bit[3*MM], N, res, off = MM;
// idea : psa; find all frequencies of values > then the current required;
// add all prefixs into array and work backwards
// res =  # of prefixs such that sum of suffix + prefix >= 0;
void upd(int x,int val){
    x+=off;
    for(; x <= 2*MM+100; x+=x&-x){ bit[x]+=val;}
}
ll query(int x){
    ll res = 0; x+=off-1;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}
int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i){
        scan(a[i]);
        if(a[i]==2) a[i] = -1;
    }
    for(int i = 1; i <= N; ++i){
        psa[i] = psa[i-1]+a[i];
    }
    upd(0, 1);
    for(int i = 1; i <= N; ++i){
        upd(psa[N]-psa[i-1], 1);
    }
    for(int i = 0; i <= N; ++i){
        upd(psa[N]-psa[i], -1); // remove the nxt value
        int val = psa[N]-psa[i]; // how many less than this,
        res+=query(val);
    }
    cout<<res<<endl;
    return 0;
}
