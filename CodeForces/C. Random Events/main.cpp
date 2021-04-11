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
const ll MM = 1e5+10;
using namespace std;
int t, N, M, a[MM], sz; double dif[MM], prob;
int main()
{
    cin>>t;
    while(t--){
        cin>>N>>M; int rt = N; double res = 1;
        for(int i = 1; i <= N; ++i) cin>>a[i];
        for(rt; rt > 0; rt--){
            if(a[rt]!=rt) break;
        }
        for(int i = 0; i < M; ++i){
            cin>>sz>>prob;
            // the probability of this range not being sorted
            // is the multiplied of all probability of 1-sorted
            if(sz >= rt) res*=(1-prob);
        }
        if(rt!=0) cout<<fixed<<setprecision(6)<<1-res<<endl;
        else cout<<fixed<<setprecision(6)<<1<<endl;
    }
    return 0;
}
