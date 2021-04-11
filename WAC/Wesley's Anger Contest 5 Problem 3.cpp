#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
ll a[MM], psum[MM];
int main()
{
    ll N,counter = 0; scan(N); ms(psum, 0);
    for(int i = 1; i <= N; ++i){
        scan(a[i]);
        psum[i] = psum[i-1]+a[i];
    }
    if(N <= 5000){
        for(int r = 1; r <= N; ++r){
            ll dstnct = 0, sumdstnct = 0;
            bool vis[MM]; ms(vis, 0);
            for(int l = r; l >= 1; --l){
                if(!vis[a[l]]){
                    vis[a[l]] = 1;
                    ++dstnct; sumdstnct+=a[l];
                }
                if(psum[r]-psum[l-1] == dstnct*sumdstnct) ++counter;
            }
        }
        cout<<counter<<endl;
    }
    else{
        for(int r = 1; r <= N; ++r){
            ll dstnct = 0, sumdstnct = 0, sum = 0, freq1[3]; ms(freq1, 0);
            bool vis[3], istrue = 1; ms(vis, 0);
            for(int l = r; l >= max(r-6, 0); --l){
                if(!vis[a[l]]){
                    vis[a[l]] = 1;
                    ++dstnct;
                }
                ++freq1[a[l]];
                for(int i = 1; i <= 2; ++i){
                    if(freq1[i]!=dstnct && vis[i]) istrue = 0;
                }
                if(istrue) ++ counter;
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}
