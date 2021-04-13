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
const ll MT = 5e3+10, MM = 505;
using namespace std;
int T, N, a[MM], par[MT], idx[MT], mid = 0x3f3f3f3f, tot, cnt[2]; bool vis[MT], side[MM];
// idea : consider that each musician is put into one of two sets
// to ensure that it's less than the amount of time we can greedily make breaks right after each other
// new problem : optimize the maximum of the 2 groups musicians are put into
// to do this just run a knapsack iterate through find the ones closest to the middle
// time complexity : o(NT) knapsack + o(N) backtrack (i think)
int main()
{
    cin>>T>>N; vis[0] = 1;
    for(int i = 0; i < N; ++i){ cin>>a[i]; tot+=a[i]; }
    for(int i = 0; i < N; ++i){
        for(int j = MT-1; j >= a[i]; --j){
            if(vis[j]) continue;
            if(vis[j-a[i]]){
                par[j] = j-a[i]; idx[j] = i; vis[j] = 1;
            }
        }
    }
    // mid - (tot - mid)
    // 2*mid - tot
    for(int i = 0; i < MT; ++i){
        if(!vis[i]) continue;
        if(abs(2*i-tot) < abs(2*mid-tot)) mid = i;
    }
    for(; mid; mid = par[mid]) side[idx[mid]] = 1;
    for(int i = 0; i < N; ++i){
        cout<<cnt[side[i]]<<" ";
        cnt[side[i]]+=a[i];
    }
}
