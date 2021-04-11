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
bool vis[MM]; int N, res = MM, p1, p2, mdist, cnt; char c;
vector<int> l;
int main()
{
    cin>>N; l.pb(1);
    for(int i = 1; i <= N; ++i){
        cin>>c;
        vis[i] = c -'0';
        if(vis[i]) l.pb(i);
    } l.pb(N);
    for(int i = 1; i < l.size(); ++i){
        if(l[i]-l[i-1]>p2-p1) p2 = l[i], p1 = l[i-1];
    }
    if(p2 == N && !vis[N]) vis[N-1] = 1;
    else if(p1 == 1 && !vis[1]) vis[p1] = 1;
    else vis[p1+p2>>1] = 1;
    for(int i = 1; i <= N; ++i) cout<<vis[i]<<" ";
    cout<<endl;
    l.clear(); l.pb(1);
    for(int i = 1; i <= N; ++i){
        if(vis[i]) l.pb(i);
    } l.pb(N);
    p2 = p1 = 0;
    for(int i = 1; i < l.size(); ++i){
        if(l[i]-l[i-1]>p2-p1) p2 = l[i], p1 = l[i-1];
    }
    if(p2 == N && !vis[N]) vis[N] = 1;
    else if(p1 == 1 && !vis[1]) vis[1] = 1;
    else vis[p1+p2>>1] = 1;
    p2 = MM; p1 = 0; l.clear();
    for(int i = 0; i <= N; ++i){
        if(vis[i]) l.pb(i);
    }
    for(int i = 1; i < l.size(); ++i){
        if(l[i]-l[i-1]<p2-p1) p2 = l[i], p1 = l[i-1];
    }
    for(int i = 1; i <= N; ++i) cout<<vis[i]<<" ";
    cout<<p2-p1<<endl;
    /*
    7
    1000001
    */

    return 0;
}
