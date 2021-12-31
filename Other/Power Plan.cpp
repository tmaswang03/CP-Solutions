#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 310;
using namespace std;
// idea: MST
// weight of edges = i.w - max(p[u], p[v]);

ll N, p[MM], cost = 0, w, hed[MM], sz[MM], mp[MM], v[MM][MM];

ll find_hed(int x) {
    if(hed[x] == x) return x;
    return hed[x] = find_hed(hed[x]);
}

void join(ll a, ll b) {
    a = find_hed(a); b = find_hed(b);
    if(sz[a] < sz[b]) swap(a, b);
    hed[b] = a; sz[a] += sz[b];
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){ cin>>p[i]; cost += p[i]; }
    for(int i = 1; i <= N; ++i) {
        mp[i] = p[i]; hed[i] = i; sz[i] = 1;
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin>>v[i][j];
        }
    }
    bool use = 1;
    while(use) {
        use = 0; ll cc = LLONG_MAX, cu = 0, cv = 0;
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                int a = find_hed(i), b = find_hed(j);
                if(a == b || v[i][j] - max(mp[a], mp[b]) > cc) continue;
                cc = v[i][j] - max(mp[a], mp[b]);
                cu = a; cv = b;
            }
        }
        if(cc < 0) {
            use = 1; mp[cu] = mp[cv] = min(mp[cu], mp[cv]); join(cu, cv); cost += cc;
        }
    }
    cout<<cost<<endl;
    return 0;
}