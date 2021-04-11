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
const ll MM = 110;
using namespace std;
int T, C, N, a[MM], tmp[MM];
int main() {
    cin>>T;
    for(int t = 1; t <= T; ++t){
        cin>>N>>C; int cnt = N*(N+1)/2-1;
        if(C<N-1||C>cnt){
            cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl; continue;
        }
        int lft = 1, rt = N; bool f = 0;
        for(int i = N; i >= 1; --i){
            if(!f){
                if(i<=C-i+2){
                    a[rt] = N-i+1; --rt; C-=i; f = !f;
                }
                else{
                    a[lft] = N-i+1; ++lft; C-=1;
                }
            }
            else{
                if(i<=C-i+2){
                    a[lft] = N-i+1; ++lft; C-=i; f = !f;
                }
                else{
                    a[rt] = N-i+1; --rt; C-=1;
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        for(int i = 1; i <= N; ++i) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
