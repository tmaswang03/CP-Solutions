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
const ll MM = 25010, MN = 5e2+10;
using namespace std;
int N, a[MM]; bool vis[2][MM]; unordered_set<int> st;
int main()
{
    vis[0][0] = vis[1][0] = 1;
    cin>>N;
    for(int i = 0; i < N; ++i) cin>>a[i];
    sort(a, a+N, greater<int>());
    for(int i = 1; i < N; ++i){
        int cur = i%2, prev = (i+1)%2;
        for(int k = 0; k < MM; ++k) vis[cur][k] = vis[prev][k];
        for(auto && j : st){
            int val = j - a[i];
            for(int k = val; k < MM; ++k){
                vis[cur][k]|=vis[prev][k-val];
            }
        }
        st.insert(a[i]);
    }
    for(int i = 0; i < MM; ++i){
        if(vis[(N-1)%2][i]) cout<<i<<" ";
    }
    return 0;
}
