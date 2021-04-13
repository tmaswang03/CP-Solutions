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
using namespace std;
ll T, N, S, ans, tot, diff;
int main()
{
    cin>>T;
    while(T--){
        cin>>N>>S; tot = N*(N+1)/2;
        diff = tot - S; ll mi = diff - N - 1, ma = diff - 1;
        // the number of values possible is diff/2;
        cout<<min((diff-1)/2 - mi, ma - diff + (diff-1)/2+1)<<endl;
    }
    return 0;
}
