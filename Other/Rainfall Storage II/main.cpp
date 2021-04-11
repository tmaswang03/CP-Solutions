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
const ll MM = 1e6+10;
using namespace std;
ll a[MM], N, prefmax[MM], sufmax[MM], res = 0;
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    // idea : keep prefix max, suffix max
    // add in max(0, min(prefixmax[i-1], suffixmax[i+1]) - a[i])
    for(int i = 1; i <= N; ++i){
        prefmax[i] = max(a[i], prefmax[i-1]);
    }
    for(int i = N; i >= 1; --i){
        sufmax[i] = max(a[i], sufmax[i+1]);
    }
    for(int i = 1; i <= N; ++i){
        res += max(0LL, min(prefmax[i-1], sufmax[i+1]) - a[i]);
    }
    cout<<res<<endl;
    return 0;
}
