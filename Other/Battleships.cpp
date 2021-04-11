#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
const ll MM = 2e3+1;
using namespace std;
ll cnt1 = 0, cnt2 = 0, S, M, N; ld res;
char cur;
int main()
{
    cin>>M>>N>>S;
    for(ll i = 1; i <= M; ++i){
        for(ll j = 1; j <= N; ++j){
            cin>>cur;
            if(cur=='X'){
                cnt1+= (min(M - S + 1, i) - max(0LL, i - S)) * (min(N - S + 1, j) - max(0LL, j - S));
            }
        }
    }
    cnt2 = (M-S+1)*(N-S+1);
    res = cnt1/(1.0*cnt2);
    cout<<fixed<<setprecision(18)<<res<<endl;
    return 0;
}
