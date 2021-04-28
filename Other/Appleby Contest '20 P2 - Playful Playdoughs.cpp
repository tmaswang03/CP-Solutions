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
ll N, Q, x, opt; unordered_map<ll, ll> umap;
int main()
{
    cin>>N>>Q;
    for(int i = 0; i < N; ++i){
        cin>>x; ++umap[x];
    }
    while(Q--){
        cin>>opt>>x;
        if(opt==1){
            umap[x/2] += umap[x];
            umap[ceil(x/2.0)] += umap[x]; umap[x] = 0;
        }
        else cout<<umap[x]<<endl;
    }
    return 0;
}