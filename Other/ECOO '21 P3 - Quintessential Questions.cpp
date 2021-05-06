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
const ll MM = 2e5+10;
using namespace std;
int N, M, K, best[MM], idx[MM], A, B, C;
int main()
{
    cin>>N>>M>>K;
    for(int i = 0; i < K; ++i){
        cin>>A>>B>>C;
        // A = professor
        // B = question
        // C = score
        if(best[B]<C){
            best[B] = C; idx[B] = A;
        }
    }
    for(int i = 1; i < N; ++i){
        if(best[i]) cout<<idx[i]<<" ";
        else cout<<-1<<" ";
    }
    if(best[N]) cout<<idx[N]<<endl;
    else cout<<-1<<endl;
    return 0;
}