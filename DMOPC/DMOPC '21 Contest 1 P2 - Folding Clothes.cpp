#include<bits/stdc++.h>
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e3+10;
using namespace std;
ll N, a[MM], M, cur, s[MM]; queue<ll> moves; bool vis[MM];
int main()
{
    // non-decreasing order
    cin>>N;
    for(int i = 1; i <= N; ++i){
        cin>>a[i]; s[i] = a[i];
    }
    sort(s+1, s+N+1, greater<ll>());
    for(int i = 1; i <= N; ++i) {
        ll cnt = 1, vi = 0;
        while(a[cnt] != s[i] || vis[cnt]) {
            if(vis[cnt]) ++vi;
            ++cnt;
        }
        vis[cnt] = 1;
        cnt = cnt - vi;
        ++M; moves.push(cnt);
        if(cnt != 1) {
            ++M; moves.push(-cnt+1);
        }
    }
    M++; moves.push(-N);
    cout<<M<<endl;
    while(!moves.empty()) {
        cout<<moves.front()<<endl; moves.pop();
    }
    return 0;
}