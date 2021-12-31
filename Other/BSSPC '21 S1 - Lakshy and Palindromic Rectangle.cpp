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
int N, M; char a[MM][MM];
// 0 1 2 3
// 2 == 2
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(a[i][j] == '.') {
                a[i][j] = a[i][M - j - 1];
                if(a[i][j] == '.') a[i][j] = a[N - i - 1][j];
                if(a[i][j] == '.') a[i][j] = a[N - i - 1][M - j - 1];
                if(a[i][j] == '.') a[i][j] = 'a';
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(a[i][j] != a[i][M - j - 1] || a[i][j] != a[N - i - 1][j]) {
                cout<<-1<<endl; return 0;
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M - 1; ++j) cout<<a[i][j];
        cout<<a[i][M-1]<<endl;
    }
    return 0;
}