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
ll a[MM], psa[MM], N, res = 1e9;
void check(int i, int pt){
    res = min(res, max({psa[N]-psa[i], psa[i]-psa[pt], psa[pt]})-min({psa[N]-psa[i], psa[i]-psa[pt], psa[pt]}));
}
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i) psa[i]=psa[i-1]+a[i];
    // idea : you want to minimize :
    // max(psa[N]-psa[i], psa[i-1]-psa[j], psa[j-1]) - min(psa[N]-psa[i], psa[i-1]-psa[j], psa[j-1])
    // for a given index,
    //
    for(int i = 2; i <= N; ++i){
        // if you pick this as right split point
        // the best split point is the one that minimizes
        // psa[i] - psa[j], psa[j]
        int pt = lower_bound(psa, psa+N, psa[i]/2)-psa;
        check(i, pt);
        if(pt>1) check(i, pt-1);
    }
    cout<<res<<endl;
    return 0;
}
