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
ll N, X, cur; vector<int> v, u;
int main()
{
    cin>>N>>X;
    if(X>(N-1)*(N-2)/2) cout<<-1<<endl;
    for(int i = 1; i <= N-2; ++i){
        if(cur+(N-1-i)<= X){ v.pb(i); cur+=N-1-i; }
        else u.pb(i);
    }
    reverse(u.begin(), u.end());
    cout<<N<<" ";
    for(int i : v) cout<<i<<" ";
    cout<<N-1<<" ";
    for(int i : u) cout<<i<<" ";
    return 0;
}
