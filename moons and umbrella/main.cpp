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
int T, X, Y, dp[MM][2]; string s;
// X = CJ
// Y = JC
int main()
{
    // if before is C after is C, fill with C
    // if before is J after is J, fill with J
    // if before is J after is C, JJC or JCC
    // if before is is C and after is J, CCJ or CJJ
    cin>>T;
    for(int t = 1; t <= T; ++t){
        cin>>X>>Y>>s;
        int idx = 0, cnt = 0; while(idx < s.length() && s[idx]=='?') ++idx;
        ++idx;
        for(idx; idx < s.length(); ++idx){
            if(s[idx]=='?'){
                char p = s[idx-1];
                while(idx < s.length() && s[idx]=='?') ++idx;
                if(s[idx]=='?') break;
                if(p=='J' && s[idx]=='C') cnt+=Y;
                else if(p=='C' && s[idx]=='J') cnt+=X;
            }
            else{
                if(s[idx]=='C'&&s[idx-1]=='J') cnt+=Y;
                else if(s[idx]=='J' && s[idx-1]=='C') cnt+=X;
            }
        }
        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }
    return 0;
}
