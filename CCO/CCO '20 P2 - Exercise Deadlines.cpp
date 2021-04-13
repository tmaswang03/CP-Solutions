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
const ll MM = 2e5+10;
using namespace std;
vector<int> days[MM];
int a[MM], N, cur, sum, bit[MM]; ll res;
priority_queue<int>pq;
void upd(int x){for(; x< MM; x+=x&-x) ++bit[x];}
int query(int x){
    int res = 0;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}
int main()
{
    scan(N);
    for(int i = 1; i <= N; ++i){
        scan(cur); days[cur].pb(i);
    }
    for(int i = 1; i <= N; ++i){
        sum+=days[i].size();
        if(sum>i){printf("-1\n"); return 0;}
    }

    for(int i = N; i >= 1; --i){
        for(auto && k : days[i]) pq.push(k);
        a[i] = pq.top(); pq.pop();
    }
    for(int i = N; i >= 1; --i){
        res+=query(a[i]);
        upd(a[i]);
    }
    printf("%lld\n", res);
    return 0;
}
