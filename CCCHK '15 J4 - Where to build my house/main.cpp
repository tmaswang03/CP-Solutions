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
using namespace std;
int L, N, x, y, res; vector<pii> v; pii a[100010];
int main()
{
    cin>>L>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i].f>>a[i].s;
    }
    sort(a, a+N);
    for(int i = 0; i < N; ++i){
        int ml = a[i].f, mr = a[i].s;
        while(a[i+1].f<=mr && i < N){
            mr = max(a[i+1].s, mr); ++i;
        }
        v.pb({ml, mr});
    }
    for(int i = 0; i < v.size()-1; ++i){
        res = max(res, v[i+1].f-v[i].s);
    }
    res = max({res, v[0].f, L-v.back().s});
    cout<<res<<endl;
    return 0;
}
