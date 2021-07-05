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
const ll MM = 3e5+10;
using namespace std;
ll x, k, Q, a[MM], top, psa[MM]; bool vis[MM];
int main()
{
    cin>>Q; vis[1] = 1;
    for(int i = 2; i < MM; ++i){
        if(vis[i]) continue;
        a[++top] = i;
        for(int j = 2; j*i < MM; ++j) vis[j*i] = 1;
    }
    for(int i = 0; i < MM; ++i) psa[i] = psa[i-1] + a[i];
    while(Q--){
        cin>>x>>k;
        int pt = lower_bound(a, a+20000, x) - a;
        cout<<a[pt+k-1]<<" "<<psa[pt+k-1] - psa[pt-1]<<endl;
    }
    return 0;
}