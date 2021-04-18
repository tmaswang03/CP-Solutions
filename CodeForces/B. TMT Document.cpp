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
const ll MM = 1e5+10;
using namespace std;
int T, N; string S; deque<int> dq[30];
// M = 12;
// T = 19;
int main()
{
    cin>>T;
    while(T--){
        cin>>N>>S; int sum = 0; bool done = 1;
        for(int i = 0; i < N; ++i){
            if(S[i]=='T') ++sum;
            else if(S[i]=='M') --sum;
            if(sum<0||sum>N/3) done = 0;
        }
        if(done && sum==N/3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
