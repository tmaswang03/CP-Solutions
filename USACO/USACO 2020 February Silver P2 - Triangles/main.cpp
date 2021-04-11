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
const ll mod = 1e9+7, MM = 1e5+10, shft = 1e4+10;
using namespace std;
ll N, x, y, res = 0; pii a[MM];  set<pii>stxy;

int main()
{
    // area = b*h
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>x>>y; stxy.insert({x, y});
    }
    for(auto && i : stxy){
        for(auto && j : stxy){
            if(stxy.count({i.f, j.s})){
                res = (res + abs((j.f-i.f)*(j.s-i.s)))%mod;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
