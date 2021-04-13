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
int N, K, a[MM], cnt, b, freq[MM]; unordered_set<int> st;
int main()
{
    cin>>N>>K; b = K; ms(freq, 0); ++freq[0];
    while(b<=1<<8){st.insert(b); b*=K;}
    for(int i = 1; i <= N; ++i){ cin>>a[i]; a[i]^=a[i-1];}
    for(int r = 1; r <= N; ++r){
        for(auto && i : st) cnt+=freq[i^a[r]];
        ++freq[a[r]];
    }
    cout<<cnt<<endl;
    return 0;
}
