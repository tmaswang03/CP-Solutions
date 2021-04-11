#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e7+10, INF = 0x3f3f3f3f;
using namespace std;
int dst[MM], N, M;
int main()
{
    ms(dst, INF);
    scan(N); scan(M);
    dst[N] = 0;
    queue<int>q;
    q.push(N);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(3*cur<= 1e7 && dst[3*cur]>dst[cur]+1){
            q.push(3*cur); dst[3*cur] = dst[cur]+1;
        }
        if(cur-1>=0 && dst[cur-1]>dst[cur]+1){
            q.push(cur-1); dst[cur-1] = dst[cur]+1;
        }
        if(cur-3>=0 && dst[cur-3]>dst[cur]+1){
            q.push(cur-3); dst[cur-3] = dst[cur]+1;
        }
        if(cur%2==0 && dst[cur/2]>dst[cur]+1){
            q.push(cur/2); dst[cur/2] = dst[cur]+1;
        }
    }
    cout<<dst[M]<<endl;
    return 0;
}
