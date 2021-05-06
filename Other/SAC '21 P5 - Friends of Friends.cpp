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
ll N, Q, opt, x, y, hed[MM], sz[MM];
ll find_hed(ll x){
    if(hed[x]==x) return x;
    return hed[x] = find_hed(hed[x]);
}
void join(int x, int y){
    x = find_hed(x); y = find_hed(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x, y);
    sz[x]+=sz[y]; hed[y] = x;
}
int main()
{
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i){
        hed[i] = i; sz[i] = 1;
    }
    while(Q--){
        cin>>opt;
        if(opt==1){
            cin>>x>>y;
            join(x, y);
        }
        else{
            cin>>x;
            cout<<sz[find_hed(x)]<<endl;
        }
    }
    return 0;
}