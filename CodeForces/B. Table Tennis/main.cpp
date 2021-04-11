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
const ll MM = 5e2+10;
using namespace std;
ll res = 0, n, k, a, wins[MM], cur, nxt, cnt; queue<ll> q;
int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; ++i){
        cin>>a; q.push(a);
    }
    cur = q.front(); q.pop();
    while(1){
        nxt = q.front(); q.pop();
        if(cur > nxt){ ++ wins[cur]; q.push(nxt); ++cnt;}
        else{
            ++wins[nxt]; q.push(cur); cur = nxt; cnt = 1;
        }
        if(wins[cur] == k || cnt >= n-1){
            cout<<cur<<endl; return 0;
        }
    }

}
