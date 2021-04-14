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
const ll MM = 1e2+10;
using namespace std;
int T, a[MM], N;
int main()
{
    cin>>T;
    for(int i = 1; i <= T; ++i){
        cin>>N; int cnt = 0;
        for(int j = 1; j <= N; ++j) cin>>a[j];
        for(int j = 1; j < N; ++j){
            int idx = j;
            while(a[idx]!=j && idx <= N) ++idx;
            cnt+=idx-j+1;
            reverse(a+j, a+idx+1);
        }
        cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
    return 0;
}
