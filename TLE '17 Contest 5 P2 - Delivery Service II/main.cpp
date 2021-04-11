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
const ll MM = 1e5+10, inf = 1e9;
using namespace std;
ll a[MM], N, D, p1, p2, strtfrwrd = inf, endfrwrd = -inf, strtbkwrd = -inf, endbkwrd = inf; bool frwrd, bkwrd;
ll func(){
    ll res = 10*inf;
    if(frwrd && bkwrd){
        res = min(res, max(strtbkwrd, endfrwrd) - strtfrwrd + max(strtbkwrd, endfrwrd) - endbkwrd);
        res = min(res, strtbkwrd - min(endbkwrd, strtfrwrd) + endfrwrd - min(endbkwrd, strtfrwrd));
        return res;
    }
    else if (frwrd) return endfrwrd-strtfrwrd;
    else return strtbkwrd-endbkwrd;
}
int main()
{
    cin>>N>>D;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 0; i < D; ++i){
        cin>>p1>>p2;
        if(a[p1]<a[p2]){
            strtfrwrd = min(strtfrwrd, a[p1]); endfrwrd = max(endfrwrd, a[p2]); frwrd = 1;
        }
        else{
            strtbkwrd = max(strtbkwrd, a[p1]); endbkwrd = min(endbkwrd, a[p2]); bkwrd = 1;
        }
    }
    if(!frwrd) strtfrwrd = -inf, endfrwrd = inf;
    if(!bkwrd) strtbkwrd = inf, endbkwrd = -inf;
    cout<<func()<<endl;
    return 0;
}
