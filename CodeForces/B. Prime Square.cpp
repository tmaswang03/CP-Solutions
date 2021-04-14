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
using namespace std;
int t, n, sum, n1;
vector<int> v;
bool isprime(int n){
    for(int i = 2; i*i <= n; ++i){
        if(n%i==0) return 0;
    }
    return 1;
}
int nxt(int n){
    while(!isprime(n)) ++n;
    return n;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n; v.clear();
        for(int i = 0; i < n-2; ++i) v.pb(1);
        sum = n-2; n1 = nxt(n);
        if(n1 - sum==2){v.pb(1); v.pb(1);}
        else if( (n1 - sum)%2==0){v.pb(0); v.pb(n1);}
        else {v.pb(1); v.pb(n1-1);}
        do {
            for(auto && i : v) cout<<i<<" ";
            cout<<endl;
        } while (next_permutation(v.begin(), v.end()));
    }
    return 0;
}
