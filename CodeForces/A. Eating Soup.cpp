#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const ll MM = 1e3+10;
bool vis[MM];
int cnt = 0, res = 0;
int main() {
    ms(vis, 0);
    int N, M, i = 1; scan(N); scan(M);
    while(cnt < M){
        vis[i] = 1; ++cnt;
        i+=2;
        if(i > N) i = 0;
    }
    for(int i = 1; i < N; ++i){
        if(vis[i]&&!vis[i-1]) ++res;
    }
    cout<<res+1<<endl;
}
