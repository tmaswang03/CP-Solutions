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
const ll MM = 1e3+10;
using namespace std;
int N, M, Q, id[MM][MM], x, y;
int main()
{
    cin>>N>>M>>Q;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j) id[i][j] = (i-1)*M+j;
    }
    while(Q--){
        cin>>x>>y; int cur = id[x][y];
        for(int i = y; i < M; ++i) id[x][i] = id[x][i+1];
        for(int i = x; i < N; ++i) id[i][M] = id[i+1][M];
        id[N][M] = cur;
//        cout<<endl;
//        for(int i = 1; i <= N; ++i){
//            for(int j = 1; j <= M; ++j) cout<<id[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<endl;
        cout<<cur<<endl;
    }
    return 0;
}
