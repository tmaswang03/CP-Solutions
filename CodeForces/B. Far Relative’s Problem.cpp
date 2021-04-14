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
const ll MM = 5e3+10;
using namespace std;
int N, m[MM], f[MM], l, r, res = 0;
char opt;
int main()
{
    scan(N); ms(m, 0); ms(f, 0);
    for(int i = 0; i < N; ++i){
        cin>>opt; scan(l); scan(r);
        if(opt=='M'){ ++m[l]; --m[r+1];}
        else{ ++f[l]; --f[r+1];}
    }
    for(int i = 0; i <= 366; ++i){
        m[i] += m[i-1]; f[i]+=f[i-1];
    }
    for(int i = 1; i <= 366; ++i){
        res = max(res, 2*(min(m[i], f[i])) );
    }
    cout<<res<<endl;
    return 0;
}
