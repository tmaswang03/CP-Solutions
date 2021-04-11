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
ll cnt = 0;
bool prime(ll N){
    for(ll i = 2; i*i <= N; ++i){
        if(N%i==0) return 0;
    }
    return 1;
}
int main()
{
    ll N, cur = 2; scan(N);
    while(cnt < N){
        if(prime(cur)){
            ++cnt; cout<<cur<<" ";
            if(cnt%10==0) cout<<endl;
        }
        ++cur;
    }
    return 0;
}
