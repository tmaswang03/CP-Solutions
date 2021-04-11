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
const ll MM = 1e5+10;
using namespace std;
vector<int>v[MM];
map<int, string> mep;
map<string, int> rmep;
int main()
{
    int M; cin>>M;
    for(int i = 1; i <= M; ++i){
        string o,r; cin>>o>>r;
        if(!rmep[o]) rmep[o] = i;
        if(!rmep[r]) rmep[r] = i;
    }
    return 0;
}
