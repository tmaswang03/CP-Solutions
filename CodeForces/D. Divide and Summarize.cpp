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
const ll MM = 1e6+10;
using namespace std;
ll t, N, Q, a[MM], s[MM], psa[MM]; unordered_set<ll>st;
// observations : if the entire left or right array has the same values then you terminate
void solve(int l, int r){
    if(r<l) return;
    st.insert(psa[r]-psa[l-1]);
    if(a[r]==a[l]) return;
    int mid = a[l]+a[r]>>1;
    int splt = upper_bound(a+l, a+r, mid)-a;
    solve(l, splt-1); solve(splt, r);
}
int main()
{
    boost();
    cin>>t;
    while(t--){
        cin>>N>>Q; st.clear();
        for(int i = 1; i <= N; ++i) cin>>a[i];
        sort(a+1, a+N+1);
        for(int i = 1; i <= N; ++i) psa[i]=psa[i-1]+a[i];
        solve(1, N);
        for(int i = 0; i < Q; ++i){
            cin>>s[i];
            if(st.count(s[i])) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
