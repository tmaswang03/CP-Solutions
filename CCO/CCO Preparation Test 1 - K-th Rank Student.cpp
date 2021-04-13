#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <ext/pb_ds/assoc_container.hpp>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set tre [MM];
int rank1[MM], parent[MM], ar[MM], umap[MM], N, M, Q;

int find_set(int a){
    if(parent[a]==a) return a;
    else return parent[a] = find_set(parent[a]);
}

void merge1(int a, int b){
    a = find_set(a); b = find_set(b);
    if(a^b){
            if(rank1[a]<rank1[b]) swap(a, b);
            for(auto && i : tre[b]){
                tre[a].insert(i);
            }
        }
        parent[b] = a; rank1[a]+=rank1[b];

}

int main()
{
    scan(N); scan(M);
    for(int i = 0; i <= N; ++i){
        rank1[i] = 1;
    }
    iota(parent, parent+N+1, 0);
    for(int i = 1; i <= N; ++i){
        scan(ar[i]);
        umap[ar[i]] = i;
        tre[i].insert(ar[i]);
    }
    for(int i = 1; i <= M; ++i){
        int a,b; scan(a); scan(b);
        merge1(a, b);
    }
    scan(Q);
    while(Q--){
        char opt; int a,b; scanf("%s", &opt); scan(a); scan(b);
        if(opt == 'Q'){
            if(b>tre[find_set(a)].size()){
                printf("-1\n");
            }
            else{
                printf("%lld\n", umap[*tre[find_set(a)].find_by_order(b-1)]);
            }
        }
        else merge1(a, b);
    }
    return 0;
}
