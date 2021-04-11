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
int K, N, a[MM], last[MM]; deque<int> dq; bool vis[MM];
int main()
{
    cin>>N>>K;
    for(int i = 0; i < N; ++i){ cin>>a[i]; last[a[i]] = i; }
    for(int i = 0; i < N; ++i){
        if(vis[a[i]]) continue;
        while(!dq.empty()&&dq.back()>a[i]&&last[dq.back()]>i){
            vis[dq.back()] = 0;
            dq.pop_back();
        }
        dq.push_back(a[i]); vis[a[i]] = 1;
    }
    while(dq.size()>1){ cout<<dq.front()<<" "; dq.pop_front(); }
    cout<<dq.front()<<endl;
    return 0;
}
