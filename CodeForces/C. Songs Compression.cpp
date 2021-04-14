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
const ll MM = 1e5+10;
using namespace std;
ll m, n, sum = 0, sum1 = 0, cnt = 0, pt = 0;
pair<ll, ll> a[MM];
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
    return a.f - a.s > b.f - b.s;
}
int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; ++i){
        cin>>a[i].f>>a[i].s; sum+=a[i].s; sum1+=a[i].f;
        if(sum > m){cout<<-1<<endl; return 0;}
    }
    sort(a, a+n, cmp);
    while(sum1 > m){
        sum1-=a[pt].f - a[pt].s; ++cnt; ++pt;
    }
    cout<<cnt<<endl;

    return 0;
}
