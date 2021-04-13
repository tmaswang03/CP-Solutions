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
ll N, M, hed[MM], sz[MM], F[MM], x, y, cnt; vector<pii> v;
int gett(int a){
    if(hed[a]==a) return a;
    return hed[a] = gett(hed[a]);
}
void join(int a, int b){
    a = gett(a); b = gett(b);
    if(sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b]; hed[b] = a;
}

int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i){
        cin>>F[i]; hed[i] = i; sz[i] = 1;
    }
    for(int i = 0; i < M; ++i){
        cin>>x>>y;
        join(x, y);
    }
    for(int i = 1; i < N; ++i){
        if(gett(i)!=gett(i+1)){
            v.pb({F[i+1]-F[i], i});
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i){
        if(gett(v[i].s)!=gett(v[i].s+1)){
            cnt+=v[i].f; join(v[i].s, v[i].s+1);
        }
    }
    cout<<cnt<<endl;
}
