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
const ll MM = 310;
using namespace std;
int N, Q, tmp[MM], a[MM], x, y, idx[MM], idxx[MM]; char opt; deque<pii> dq;
int main()
{
    /*
4 5
B 3 4
B 1 3
E 2 3
E 1 2
Q 1 2 3 4
4 3 2 1
*/
    boost();
    cin>>N>>Q;
    for(int i = 0; i < N; ++i) idx[i] = idxx[i] = i;
    while(Q--) {
        cin>>opt;
        if(opt == 'B') {
            cin>>x>>y; dq.push_front({x-1, y-1}); swap(idx[x-1], idx[y-1]);
        }
        else if(opt == 'E') {
            cin>>x>>y; dq.push_back({x-1, y-1});
            swap(idxx[x-1], idxx[y-1]);
        }
        else {
            for(int i = 0; i < N; ++i) cin>>tmp[i];
            for(int i = 0; i < N; ++i) a[idxx[i]] = tmp[i];
            for(int i = 0; i < N-1; ++i) cout<<a[idx[i]]<<" ";
            cout<<a[idx[N-1]]<<endl;
        }
    }
    return 0;
}