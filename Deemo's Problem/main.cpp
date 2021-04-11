#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MM = 1e5+10;
using namespace std;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seed1); uniform_int_distribution<ll> dis(1, 1e12);
ll w[MM], N, M, pref = 0, mod = 0, res = 0;
unordered_map<ll, ll> umap;
int main()
{
    scan(N); scan(M);
    for(int i = 1; i <= M; ++i){
        w[i] = dis(gen); mod+=w[i];
    }
    umap[0] = 1;
    for(int i = 0; i < N; ++i){
        int a; scan(a);
        pref = (pref+w[a])%mod;
        res+= umap[pref]; ++umap[pref];
    }
    cout<<res<<endl;
    return 0;
}
