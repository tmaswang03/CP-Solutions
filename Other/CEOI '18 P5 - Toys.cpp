#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
char _;
vector<ll> sols;
void factors (ll cur,ll fact,ll sum){
    sols.pb(sum+cur-1);
    for(int i = fact; i*i <= cur; ++i){
        if(!(cur%i)){
            factors(cur/i, i, sum+i-1);
        }
    }
}
int main()
{
    ll N, res; scan(N);
    factors(N, 2, 0);
    sort(sols.begin(), sols.end());
    res = unique(sols.begin(), sols.end()) - sols.begin();
    cout<<res<<endl;
    for(int i = 0; i < res; ++i){
        cout<<sols[i]<<" ";
    }cout<<endl;
    return 0;
}
