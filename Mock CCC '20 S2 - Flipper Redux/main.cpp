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
bool a[MM][MM]; int N, M; vector<pair<char, int> > out;
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j) cin>>a[i][j];
    }
    for(int i = 1; i <= N; ++i){
        if(a[i][1]){
            out.pb({'R', i});
            for(int j = 1; j <= N; ++j) a[i][j]^=1;
        }
    }
    for(int i = 2; i <= N; ++i){
        if(a[1][i]){
            out.pb({'C', i});
            for(int j = 1; j <= N; ++j) a[j][i]^=1;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(a[i][j]){ cout<<-1<<endl; return 0; }
        }
    }
    cout<<out.size()<<endl;
    for(auto && i : out) cout<<i.f<<" "<<i.s<<endl;
    return 0;
}
