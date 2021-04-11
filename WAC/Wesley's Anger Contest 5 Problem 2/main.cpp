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
int a[MM], max1[MM], min1[MM], N, Q;
int main()
{
    boost();
    cin>>N>>Q; ms(max1, 0); ms(min1, 0);
    for(int i = N-1; i>=0; --i){
        cin>>a[i];
    }
    max1[0] = a[0], min1[0] = -a[0];
    for(int i = 1; i < N; ++i){
        max1[i] = max(max1[i-1], a[i]);
        min1[i] = max(min1[i-1], -a[i]);
    }
    for(int i = 0; i < Q; ++i){
        int l, e; cin>>l>>e;
        int su = l+e, se = e-l;
        int temp1 = upper_bound(max1, max1+N, su) - max1;
        int temp2 = upper_bound(min1, min1+N, se) - min1;
        cout<<min(temp1, temp2)<<endl;
    }
    return 0;
}
