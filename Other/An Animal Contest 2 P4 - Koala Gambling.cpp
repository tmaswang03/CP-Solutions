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
const ll MM = 6e2+10;
using namespace std;
int T, a[MM], N;
int main()
{
// dp[l][r] = max(sum diff between a[l] - dp[l+1][r], a[r] - dp[l][r-1]
// dp[l-1][r]
    boost();
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 0; i < N; ++i) cin>>a[i];
        sort(a, a+N);
        if(N%2){
            for(int i = 0; i < N-1; ++i) cout<<a[i]<<" ";
            cout<<a[N-1]<<endl;
        }
        else{
            if(a[0]==a[N-1]) cout<<-1<<endl;
            else{
                for(int i = 0; i < N/2-1; ++i){
                    cout<<a[i]<<" "<<a[i+N/2]<<" ";
                }
                cout<<a[N/2-1]<<" "<<a[N-1]<<endl;
            }
        }
    }
    return 0;
}