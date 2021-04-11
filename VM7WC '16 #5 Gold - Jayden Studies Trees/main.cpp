#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e4+10;
using namespace std;
vector<int> v[MM];
int N, ind, len;
void getdia(int cur, int par, int curlen){
    if(curlen>len){
        len = curlen; ind = cur;
    }
    for(auto && i : v[cur]){
        if(i==par) continue;
        getdia(i, cur, curlen+1);
    }
}

int main()
{
    scan(N);
    for(int i = 0; i < N-1; ++i){
        int a,b ; scan(a); scan(b);
        v[a].pb(b); v[b].pb(a);
    }
    getdia(1, -1, 0);
    len = 0;
    getdia(ind, -1, 0);
    printf("%d\n", len);
    return 0;
}
