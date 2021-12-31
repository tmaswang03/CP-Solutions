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
const ll MM = 1e3+10, inf = 1e9+10;
using namespace std;
int N, M, dp[MM][MM], a[MM][MM], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1}; char c;
struct coord{
    int x, y, val;
};
bool operator<(coord n, coord m) {
    if(n.val == m.val) {
        if(n.x == m.x) return n.y < m.y;
        return n.x < m.x;
    }
    return n.val < m.val;
}
set<coord> st;
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cin>>c; dp[i][j] = inf;
            if(c=='C') a[i][j] = 1;
        }
    }
    dp[1][1] = a[1][1];
    st.insert({1, 1, dp[1][1]});
    while(!st.empty()) {
        coord cur = *st.begin(); st.erase(st.begin());
        for(int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
            if(dp[nx][ny] > dp[cur.x][cur.y] + a[nx][ny]) {
                if(dp[nx][ny] != inf) {;
                    st.erase(st.find({nx, ny, dp[nx][ny]}));
                }
                dp[nx][ny] = dp[cur.x][cur.y] + a[nx][ny];
                st.insert({nx, ny, dp[nx][ny]});
            }
        }
    }
    cout<<dp[N][M]<<endl;
    return 0;
}