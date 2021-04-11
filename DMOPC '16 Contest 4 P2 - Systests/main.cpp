#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ll B; scan(B);
    vector<tuple<ll, ll, ll> >v;
    ll total = 0;
    for(ll i = 0; i < B; ++i){
        ll F,E,P; scan(F); scan(E); scan(P);
        v.pb({F,E,P});
    }
    ll F; scan(F);
    ll test[F+1];
    for(ll i = 0; i < F; ++i){
        ll t; scan(t);
        test[i]=t;
    }
    sort(test,test+F);
    for(int i = 0; i < v.size(); ++i){
        ll temp1 = lower_bound(test,test+F, get<0>(v[i])) - test;
        if(test[temp1]>get<1>(v[i])) total+=get<2>(v[i]);
    }
    cout<<total<<endl;
    return 0;
}
