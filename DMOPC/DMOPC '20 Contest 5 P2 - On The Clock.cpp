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
const ll MM = 1e6+10;
using namespace std;
ll N, M, res; vector<pii> pt;
ll fl(ll x){
    return x*N/M;
}
ll cl(ll x){
    return (x*N+M-1)/M;
}
int main()
{
    cin>>N>>M; 
    for(int i = 0; i < M; ++i){
        int lft = i, rt = i+1;
        res+=cl(rt) - fl(lft);
    }
    cout<<res<<endl;
    for(int i = 0; i < M; ++i){
        int lft = i, rt = i+1;
        for(int j = fl(lft)+1; j <= cl(rt); ++j){
            pt.pb({j, i+1});
        }
    }
    sort(pt.begin(), pt.end());
    for(auto && i : pt) cout<<i.f<<" "<<i.s<<endl;
    return 0;
}