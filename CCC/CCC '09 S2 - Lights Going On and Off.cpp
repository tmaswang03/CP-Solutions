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
using namespace std;
int R, L, a[35], vis[35][300], tmp; set<int> st;
void dfs(int cur, ll prev) {
    if(cur==R) {
        st.insert(prev); return;
    }
    ll x = a[cur]^prev, y = a[cur];
    if(!vis[cur][x]) {
        dfs(cur+1, x); vis[cur][x] = 1;
    }
    if(!vis[cur][y]) {
        dfs(cur+1, y); vis[cur][y] = 1;
    }
}
int main()
{
    cin>>R>>L;
    for(int i = 0; i < R; ++i) {
        ll cur = 0;
        for(int j = 0; j < L; ++j){
            cin>>a[i]; cur<<=1; cur|=a[i];
        }
        a[i] = cur;
    }
    tmp = a[0];
    dfs(1, tmp);
    cout<<st.size()<<endl;
    return 0;
}