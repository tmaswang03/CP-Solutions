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
const ll MM = 1e5+10;
using namespace std;
ll N, K, Q, a[MM], psa[MM];
int main()
{
    boost();
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    sort(a+1, a+N+1, greater<ll>());
    for(int i = 1; i <= N; ++i){
        psa[i] = psa[i-1]; psa[i] = max(psa[i], psa[i-1] + a[i]);
    }
    while(Q--){
        cin>>K;
        cout<<psa[K]<<endl;
    }
    return 0;
}