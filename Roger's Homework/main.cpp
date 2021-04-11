#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
int N, cur, d, p, maxd; vector<int> v[MM];
ll res;
priority_queue<int> pq;
int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i){
        scana(d, p); v[d].pb(p);
        maxd = max(d, maxd);
    }
    for(int i = maxd; i>0; --i){
        for(auto && k : v[i]) pq.push(k);
        if(!pq.empty()){res+=pq.top(); pq.pop();}
    }
    cout<<res<<endl;
    return 0;
}
