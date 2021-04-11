#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
#define ms(a,b) memset(a,b,sizeof(a));
using namespace std;

int main()
{
    int N; gc(N);
    ll arr[51];
    ll total = 0;
    for(int i = 0; i < N; ++i){
        ll a; gc(a); total+=a;
        arr[i]=a;
    }
    bool possible = 1;
    sort(arr,arr+N, greater<int>());
    if(arr[0]>total-arr[0]){
        possible = 0;
    }
    else if(total%2==1){
        possible = 0;
    }
    printf(possible ? "YES\n" : "NO\n");
    return 0;
}
