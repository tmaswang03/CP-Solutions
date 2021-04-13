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
    int N,Q; scan(N); scan(Q);
    ll arr[N+1];
    for(int i = 0; i < N; ++i){
        ll x,y; scan(x); scan(y);
        arr[i]= x*x+y*y;
    }
    sort(arr,arr+N);
    for(int i = 0; i < Q; ++i){
        ll r; scan(r);
        ll temp1 = upper_bound(arr, arr+N, r*r)-arr ;
        cout<<temp1<<endl;
    }
    return 0;
}
