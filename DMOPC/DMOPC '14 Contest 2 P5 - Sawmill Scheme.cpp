#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10;
using namespace std;
vector<int> v[MM];
ld a[MM];
int main()
{
    int N, M; scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        int src, dst; scan(src); scan(dst);
        v[src].pb(dst);
    }
    for(int i = 1; i <= N; ++i) a[i] = 0;
    a[1] = 1.0;
    for(int cur = 1; cur <= N; ++cur){
        ld newprob = a[cur]/(ld)(v[cur].size());
        for(auto && i : v[cur]){
            a[i] += newprob;
        }
    }
    for(int i = 1; i <= N; ++i){
        if(v[i].empty()) cout<<fixed<<setprecision(9)<<a[i]<<"\n";
    }
    return 0;
}
