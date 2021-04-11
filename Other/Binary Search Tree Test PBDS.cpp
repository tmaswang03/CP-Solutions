#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
using namespace std;
typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll, ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
unordered_map<int, int> umap;
using namespace std;
ordered_set tre;
ll t = 0, N, M, last = 0, val;
char opt;
int main()
{
    boost();
    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        cin>>val;
        tre.insert({val, t++});
        ++umap[val];
    }
    while(M--){
        cin>>opt;
        cin>>val;
        if(opt == 'I'){
            tre.insert({val^last, t++});
            ++umap[val^last];
        }
        else if(opt == 'S'){
            last = tre.find_by_order((val^last)-1)->f;
            cout<<last<<"\n";
        }
        else if(opt == 'R'){
            if(umap[val^last]!=0){ tre.erase(*tre.lower_bound({val^last, 0})); --umap[val^last];}
        }
        else{
            if(umap[val^last]!=0) last = tre.order_of_key(*tre.lower_bound({val^last, 0}))+1;
            else last = -1;
            cout<<last<<"\n";
        }
    }
    while(!tre.empty()){
        cout<<tre.find_by_order(0)->f<<" ";
        tre.erase(*tre.find_by_order(0));
    }
    return 0;
}
