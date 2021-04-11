#include<bits/stdc++.h>
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
const ll MAXT = 2e6+10;
using namespace std;
ll M,K, psa[MAXT]; ld N;
struct armor{
    ll t; ld ab;
};
armor a[6];
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>N>>M>>K; ms(psa, 0);
    for(int i = 0; i < K; ++i){
        int t; ld abs; cin>>t>>abs;  a[i] = {t,abs};
    }
    for(int i = 0; i < M; ++i){
        int s,l,x; cin>>s>>l>>x;
        psa[s]+=x; psa[s+l]-=x;
    }
    for(int i = 1; i < MAXT; ++i){
        psa[i]+=psa[i-1];
    }
    for(int i = 0; i < MAXT; ++i){
        ld dmg = 0x3f3f3f;
        for(int j = 0; j < K; ++j){
            dmg = min(dmg, 1.0*(psa[i]-a[j].t)*(1.0-0.01*a[j].ab));
        }
        N-=max((ld)0,dmg);
    }
    if(N>0.0){
        cout<<fixed<<setprecision(2)<<N<<endl;
    }
    else cout<<"Act Like A Cactus."<<endl;
    return 0;
}
