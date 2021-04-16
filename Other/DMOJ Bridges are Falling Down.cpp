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
ll N, M, hed[MM], sz[MM], res[MM], num; pii a[MM];  vector<int> v[MM];
int find_par(int x){ return hed[x] == x ? x : hed[x] = find_par(hed[x]); }
void join (int a, int b){
     a = find_par(a); b = find_par(b);
     if(sz[a]<sz[b]) swap(a, b);
     hed[b] = a; sz[a]+=sz[b];
}
ll calc(ll in){ return in*(in-1)/2; }
int main()
{
    cin>>N>>M; num = calc(N);
    for (int i = 1; i <= N; ++i){
        hed[i] = i; sz[i] = 1;
    }
    for(int i = 1; i <= M; ++i){
        cin>>a[i].f>>a[i].s;
    }
    for(int i = M; i >= 1; --i){
        res[i] = num;
        int x = find_par(a[i].f), y = find_par(a[i].s);
        if(find_par(x)!=find_par(y)){
            num-=sz[x]*sz[y];
            join(x, y);
        }
    }
    for(int i = 1; i <= M; ++i) cout<<res[i]<<endl;
    return 0;
}
