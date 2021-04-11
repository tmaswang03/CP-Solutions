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
const ll MM = 1e5+10;
using namespace std;
string vow = "aeiou", s; int N, C, V, cntv[MM], cntc[MM], mc, mv;
bool check(char c){
    for(int i = 0; i < vow.length(); ++i) if(vow[i]==c) return 1;
    return 0;
}
int main()
{
    cin>>N>>C>>V>>s;
    for(int i = 1; i <= N; ++i){
        if(s[i-1]=='y') cntv[i] = cntv[i-1]+1, cntc[i] = cntc[i-1]+1;
        else if(check(s[i-1])) cntv[i] = cntv[i-1]+1;
        else cntc[i] = cntc[i-1]+1;
        mc = max(mc, cntc[i]); mv = max(mv, cntv[i]);
    }
    if(mc>C||mv>V) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
