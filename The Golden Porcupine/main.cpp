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
const ll MAXN = 1e5+2;
ll da[MAXN], db[MAXN], dc[MAXN];
using namespace std;
int main()
{
    int N, T; scan(N); scan(T);
    for(int i = 0; i < N; ++i){
        ll l,r,a,b,c; scanf("%i %i %i %i %i",&l, &r, &a, &b, &c);
        da[l]+=a; da[r+1]-=a; db[l]+=b-2*a*l; db[r+1]-=b-2*a*l; dc[l]+=a*l*l-b*l+c; dc[r+1]-=a*l*l-b*l+c;
    }
    for(int i = 1; i <= T; ++i){
        da[i]+=da[i-1];
        db[i]+=db[i-1];
        dc[i]+=dc[i-1];
    }
    for(int i = 1; i <= T; ++i){
        cout<<da[i]*i*i + db[i]*i + dc[i]<<" ";
     }
    return 0;
}
