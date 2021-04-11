#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace std;
using namespace __gnu_pbds;
// https://codeforces.com/blog/entry/11080
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll MM = 5e5+10;
int N, Q, a[MM];

int main()
{
    scanf("%d%d", &N, &Q);
    unordered_map<int, ordered_set> tre;
    for(int i = 1; i <= N; ++i) tre[0].insert(i);
    for(int i = 0; i < Q; ++i){
        int opt; scanf("%d", &opt);
        if(opt==1){
            int x; scanf("%d", &x);
            tre[a[x]].erase(tre[a[x]].upper_bound(x));
            ++a[x];
            tre[a[x]].insert(x);
        }
        else if(opt == 2){
            int x; scanf("%d", &x);
            tre[a[x]].erase(tre[a[x]].upper_bound(x));
            --a[x];
            tre[a[x]].insert(x);
        }
        else{
            int l, r, c; scanf("%d%d%d", &l, &r, &c);
            printf("%d\n", tre[c].order_of_key(r+1)-tre[c].order_of_key(l));
        }
    }
    return 0;
}
