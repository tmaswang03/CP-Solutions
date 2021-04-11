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
vector<int> v, t; int cur;
int main()
{
    int N; scan(N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scan(cur); v.pb(cur);
        }
        sort(v.begin(), v.end()); t.pb(v[N/2]);
        v.clear();
    }
    sort(t.begin(), t.end());
    printf("%d\n", t[N/2]);
    return 0;
}
