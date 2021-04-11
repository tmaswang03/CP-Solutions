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
const ll MM = 1e6+10;
using namespace std;
int N, X, h[MM];
int calc(){
    int cnt;
    for(int i = 0; i < N; ++i){
        if((h[i]+h[(i+1)%N])%2==0) ++cnt;
    }
    return cnt;
}
int main()
{
    cin>>N>>X;
    // just need 1 and 0
    // remove happiness of one alpaca if opposite parody with next
    // total possible happy alpacas : N;
    // remove : N-X;
    // idea : make first N
    // e e e e o
    for(int i = 0; i < N-X+1; ++i) h[i] = i;
    if(calc()==X){
        for(int i = 0; i < N-1; ++i) cout<<h[i]<<" ";
        cout<<h[N-1]<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
