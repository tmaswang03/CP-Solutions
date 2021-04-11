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
const ll MM = 1e6+10;
using namespace std;
int a[MM], b[MM], val[MM], N, M, K, res =  0x3f3f3f3f;
bool solve(int m){
    ms(val, 0);
    int idx = 0;
    for(int i = 0; i < N; ++i){
        while(b[idx]<a[i]-K && idx < M || val[idx]==m) ++idx;
        if(b[idx]>a[i]||b[idx]<a[i]-K) return 0;
        if(b[idx]>=a[i]-K&&b[idx]<=a[i]&&val[idx]<m){
            ++val[idx];
        }
    }
    return 1;
}
int main()
{
    cin>>N>>M>>K;
    for(int i = 0; i < N; ++i) cin>>a[i];
    for(int i = 0; i < M; ++i) cin>>b[i];
    sort(a, a+N); sort(b, b+M);
    int lo = 1, hi = N, mid;
    while(lo < hi){
        mid = lo+hi>>1;
        if(solve(mid)){
            res = mid; hi = mid;
        }
        else lo = mid+1;
    }
    if(res!=0x3f3f3f3f) cout<<res<<endl;
    else cout<<-1<<endl;
    return 0;
}
