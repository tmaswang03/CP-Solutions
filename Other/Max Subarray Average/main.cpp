#include<bits/stdc++.h>
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
const ll MM = 1e5+10;
using namespace std;
int N,F, a[MM];
int avg, res;
int main()
{
    scan(N); scan(F);
    deque<int>dq;
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    for(int i = 0; i <= N; ++i){
        while(dq.size() > F && (1.0*(avg-dq.front()))/(1.0*dq.size()-1) > (1.0*avg)/(1.0*dq.size())){
              avg-=dq.front();
              dq.pop_front();
        }
        res = max(res, (int)(1000*((1.0*avg)/(1.0*dq.size()))));
        dq.push_back(a[i]);
        avg+=a[i];
    }
    while(dq.size() > F && (1.0*(avg-dq.front()))/(1.0*dq.size()-1) > (1.0*avg)/(1.0*dq.size())){
          avg-=dq.front();
          dq.pop_front();
        }
    res = max(res, (int)(1000*((1.0*avg)/(1.0*dq.size()))));
    cout<<res<<endl;
    return 0;
}
