#include<bits/stdc++.h>
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
const ll MM = 1e3+10;
using namespace std;
ll N, K, dp[MM][5], a[4] = {0, 1, 2, 3}, res;
/*
Let's call a permutation an almost identity permutation iff there exist at least n - k indices i (1 ≤ i ≤ n) such that pi = i.
*/
ll gett(ll n, ll r){
    ll ans = 1;
    for(int i = n; i > n-r; --i) ans*=i;
    for(int i = 2; i <= r; ++i) ans/=i;
    return ans;
}
bool check(int x){
    for(int i = 0; i < x; ++i){
        if(a[i]==i) return 0;
    }
    return 1;
}
int main()
{
    // uhhh choose 0 -> K characters to make diff (NcK)
    // the number of diff ways to do that is to imagine like K characters
    // eg : 4
    cin>>N>>K;
    for(int i = 0; i <= K; ++i){
        sort(a, a+i);
        ll ch = gett(N, i);
        do{
            if(check(i)) res+=ch;
        } while(next_permutation(a, a+i));
    }
    cout<<res<<endl;
    return 0;
}
