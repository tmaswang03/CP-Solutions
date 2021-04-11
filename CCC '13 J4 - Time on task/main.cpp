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
int T, cs, cur, res = 0;
vector<int> c;

int main()
{
    scan(T); scan(cs);
    for(int i = 0; i < cs; ++i){
        scan(cur); c.pb(cur);
    }
    sort(c.begin(), c.end());
    for(auto && i : c){
        if(i > T) break;
        ++res; T-=i;
    }
    cout<<res<<endl;
    return 0;
}
