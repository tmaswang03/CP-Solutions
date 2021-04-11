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
const ll MN = 1e5+10, MM = 1e6+10;
using namespace std;
int N, M, a[MN], first[MM], last[MM], res = 0, x, y;
int main()
{
    cin>>N>>M; ms(first, 0x3f3f3f);
    for(int i = 0; i < N; ++i){
        cin>>a[i];
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }
    while(M--){
        cin>>x>>y;
        res = max(res, last[y]-first[x]+1);
    }
    cout<<res<<endl;
    return 0;
}
