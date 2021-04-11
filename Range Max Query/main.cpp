#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10, lg2 = 18;
using namespace std;
ll a[MM], N, M, sparse[MM][lg2], LOG[MM];
void initsparse(){
    LOG[1] = 0;
    for(int i = 2; i <= N; ++i) LOG[i] = LOG[i/2]+1;
    for(int i = 1; i <= N; ++i) sparse[i][0] = a[i];
    for(int lg = 1; lg <= lg2; ++lg){
        int sz = 1<<lg, psz = 1<<(lg-1);
        for(int i = 1; i <= N-sz+1; ++i){
            sparse[i][lg] = max(sparse[i][lg-1], sparse[i+psz][lg-1]);
        }
    }
}

ll query (int l, int r){
    int sz = r-l+1;
    return max(sparse[l][LOG[sz]],sparse[r-(1<<LOG[sz])+1][LOG[sz]]);
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i)
        cin>>a[i];
    initsparse();
    for(int i = 0; i < M; ++i){
        int L, R; scanf("%d%d", &L, &R);
        printf("%lld\n", query(L, R));
    }
    return 0;
}
