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
ll const MAXN = 1e7+1;
ll diff[MAXN+5], l, r, N, res;
using namespace std;
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>l>>r;
        diff[l]+=1; diff[r]-=1;
    }
    for(int i = 1; i <= 1e7; ++i){
        diff[i]+=diff[i-1];
        res = max(res, diff[i]);
    }
    cout<<res<<endl;
    return 0;
}
