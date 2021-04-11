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
const ll MM = 1e5+10, MN = 1e4+10;
using namespace std;
int N, Q, a[MM], l, r, x; vector<int> v[MN];

int main()
{
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i){ cin>>a[i]; v[a[i]].pb(i); }
    while(Q--){
        cin>>l>>r>>x;
        bool get = 0;
        for(int i = 1; i*i < x; ++i){
            if(x%i!=0||x/i>=MN) continue;
            int p1 = lower_bound(v[i].begin(), v[i].end(), l) - v[i].begin();
            int p2 = lower_bound(v[x/i].begin(), v[x/i].end(), l) - v[x/i].begin();
            if(p1<v[i].size()&&p2<v[x/i].size()&&v[i][p1]<=&&v[x/i][p2]<=r){ cout<<"YES"<<endl; get = 1; break; }
        }
        if(!get) cout<<"NO"<<endl;
    }
    return 0;
}
