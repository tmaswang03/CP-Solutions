#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int N;
vector<int> v[7];
unordered_set<int>st;
int dfs(int cur, int mask){
    mask|=(1<<cur);
    for(auto && i : v[cur]){
        mask|=dfs(i, mask);
    }
    return mask;
}
int main()
{
    scan(N);
    for(int i = 1; i <= N-1; ++i){
        int a; scan(a); v[a].pb(i);
    }
    for(int i = 1; i < 1<<N;  ++i){
        int cur = 0;
        for(int k = 1; k < N; ++k){
            if(i&(1<<k)) cur|=dfs(k, 0);
        }
        st.insert(cur);
    }
    printf("%d\n", st.size());
    return 0;
}
