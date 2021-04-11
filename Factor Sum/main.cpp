#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e2+10;
using namespace std;
ll cur, N; unordered_map<ll, ll> umap;
// compute factors in o(sqrt(N)), check for primality o(sqrt(N))
// stop if : > 1e12, over 1k ops
ll sum(ll cur){
    ll res = 1;
    if(umap[cur]) return umap[cur];
    for(ll i = 2; i*i <= cur; ++i){
        if(cur%i!=0) continue;
        if(i*i==cur) res += i;
        else res = res + cur/i + i;
    }
    return umap[cur] = res;
}
bool prime (ll cur){
    if(cur==2) return 1;
    if(cur%2==0) return 0;
    for(ll i = 3; i*i <= cur; i+=2){
        if(cur%i==0) return 0;
    }
    return 1;
}
void solve(ll cur){
    ll res = cur, cnt = 0;
    while(!prime(res)){
        if(cnt>=1000||res>1e12){
            cout<<"INFINITY"<<endl; return;
        }
        res = sum(res);
        ++cnt;
    }
    cout<<res<<" "<<cnt<<endl;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>cur; solve(cur);
    }
    return 0;
}
