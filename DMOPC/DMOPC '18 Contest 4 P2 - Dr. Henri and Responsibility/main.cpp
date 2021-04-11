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
const ll MM = 490005;
using namespace std;
int N, x, res = 0x3f3f3f3f, tot; bool vis[MM];
int main()
{
    cin>>N; vis[0] = 1;
    while(N--){
        cin>>x; tot+=x;
        for(int i = MM-1; i >= x; --i) vis[i]|=vis[i-x];
    }
    for(int i = 0; i < MM; ++i){
        res = min(res, abs(2*i-tot));
    }
    cout<<res<<endl;
    return 0;
}
