#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;

using namespace std;

int main()
{
    ll arr[MAXN];
    int N,Q; scan(N); scan(Q);
    for(int i = 0; i < N; ++i){
        ll temp; scan(temp);
        arr[i]=temp;
    }
    sort(arr,arr+N);
    for(int i = 0; i < Q; ++i){
        ll L,R; scan(L); scan(R);
        ll j = 0;
        ll counter= 0;
        int p1 , p2;
        p1 = lower_bound(arr,arr+N, L)-arr;
        p2 = upper_bound(arr,arr+N,R)-arr;
        cout<<p2-p1<<endl;
    }
    return 0;
}
