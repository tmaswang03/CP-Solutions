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
const ll MM = 1e5+10;
using namespace std;
int N, Q;
int sz[MM], par[MM];
int find_set(int a){
    if(par[a]^a) return par[a] = find_set(par[a]);
    else return a;
}

bool eq (int a, int b){return find_set(a) == find_set(b);}
void join(int a, int b){
    a = find_set(a); b = find_set(b);
    if(a^b){
        if(sz[a]<sz[b]) swap(a,b);
        par[b] = a;
        sz[a]+=b;
    }
}


int main()
{
    int N, Q; scan(N); scan(Q);
    iota(par, par+N, 0);
    fill(sz, sz+N+1, 1);
    for(int i = 0; i < Q; ++i){
        char opt; scanf("%c", &opt);
        int c1, c2; scan(c1); scan(c2);
        if(opt=='A') join(c1, c2);
        else printf(eq(c1, c2) ? "Y\n" : "N\n");
    }
    return 0;
}
