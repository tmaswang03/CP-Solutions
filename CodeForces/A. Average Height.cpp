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
const ll MM = 2e3+10;
using namespace std;
int T, N, a[MM];
bool cmp (int a, int b){
    return a%2 > b%2;
}
int main()
{
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 0; i < N; ++i) cin>>a[i];
        sort(a, a+N, cmp());
        for(int i = 0; i < N; ++i) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
