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
const ll MM = 1e3+10;
using namespace std;
int a[MM], N, K, res = 0; priority_queue<int>pq;
// the K/2 largest berry baskets are taken
// idea : take all of the largest trees,
void run(int sub){
    while(!pq.empty()) pq.pop();
    for(int i = 1; i <= N; ++i) pq.push(a[i]);
    int cnt = 0, ret = 0;
    while(!pq.empty()&&cnt<K){
        ++cnt; // current tree you're on
        int cur = pq.top(); pq.pop();
        if(cnt>K/2) ret+=cur;
        if(cur-sub>0&&cnt<=K/2) pq.push(cur-sub);
        if(cnt>K/2&&cur>sub) return;
    }
    res = max(res, ret);
}
int main()
{
    cin>>N>>K;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    sort(a+1, a+N+1, greater<int>());
    for(int i = 0; i <= a[1]; ++i) run(i);
    cout<<res<<endl;
    return 0;
}
