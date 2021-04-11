#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
// p[i] = 1 if you take, else p[i] = p[i-1]+1;
int N, o[MM], nxt[MM], ma, mi;
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i) cin>>o[i];
    for(int i = N-1; i >= 0; --i){
        if(!o[i+1]) nxt[i] = nxt[i+1]+1;
        else nxt[i] = 1;
        if(o[i] && o[i+nxt[i]] && o[i+nxt[i]]>nxt[i]+o[i]){
            cout<<-1<<endl; return 0;
        }
    }
    for(int i = 0; i < N; ++i){
        if(o[i]) continue;
        if(o[i+nxt[i]]<1+nxt[i]) ++ma;
        else if(1+nxt[i]==o[i+nxt[i]]) ++mi, ++ma;

    }
    cout<<mi<<" "<<ma<<endl;
    return 0;
}
