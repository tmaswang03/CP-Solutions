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
const ll MM = 30;
using namespace std;
int N, M, a[MM][MM], res, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
void gett(int val, int x, int y){
    queue<pii> q;
    while(!q.empty()) q.pop();
    q.push({x, y});
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = cur.f + dx[i], ny = cur.s + dy[i];
            if(nx<1||ny<1||nx>N||ny>M){
                add = 0; return;
            }
            if(a[nx][ny]>=val) add = min(add, a[nx][ny] - val);
        }
    }
}
int main()
{
    for(int t = 0; t < 5; ++t){
        cin>>N>>M; ms(a, 0); res = 0;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j) cin>>a[i][j];
        }
        // new idea : bfs from the point, grab the minimum of all values that you meet;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                cur = a[i][j]; int add = 0x3f3f3f;
                gett(cur, i, j);
                res+=add;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
