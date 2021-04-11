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
using namespace std;
ll N, L, S, a, b, x, cur, res; vector<pii>v;
int main()
{
    cin>>N>>L>>S; v.pb({0, 0});
    for(int i = 0; i < N; ++i){
        cin>>a>>b>>x; v.pb({a, -x}); v.pb({b+1, x});
    }
    sort(v.begin(), v.end()); v.pb({L, 0});
    for(int i = 1; i < v.size(); ++i){
        cur-=v[i].s;
        while(v[i+1].f==v[i].f){
            ++i; cur-=v[i].s;
        }
        if(cur>=S){
            L-=v[i+1].f-v[i].f;
        }
    }
    cout<<L<<endl;
    return 0;
}
