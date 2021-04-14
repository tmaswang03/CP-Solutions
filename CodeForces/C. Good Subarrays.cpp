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
const ll MM = 1e5+10, MN = 1e6;
using namespace std;
ll a[MM], t, n, freq[MN], cnt; string str;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>str; cnt = 0;
        for(int i = 0; i < n; ++i){ a[i] = (str[i]-'0'); a[i]+=a[i-1]; }
        // for a given index r, find out how many indeces have
        // a[r] - a[l-1] = r-l+1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                cnt+=(a[i]-a[j-1]==i-j+1);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
