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
const ll MM = 1e7+10;
using namespace std;
bool vis[MM]; int N, k, c, sum, res = 1e9;
int main()
{
    cin>>N; vis[0] = 1;
    while(N--){
        cin>>k>>c; sum+=k*c;
        int cnt = k;
        for(int i = 1; i <= k>>1; i<<=1){
            cnt-=i;
            for(int j = MM-1; j >= i*c; --j) vis[j]|=vis[j-i*c];
        }
        for(int j = MM-1; j >= cnt*c; --j) vis[j]|=vis[j-cnt*c];
    }
    for(int i = 0; i <= sum; ++i){
        if(!vis[i]) continue;
        res = min(res, abs(sum - 2*i));
    }
    cout<<res<<endl;
    return 0;
}
