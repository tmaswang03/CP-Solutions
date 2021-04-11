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
using namespace std;
ll dp[5]; string s;
int main()
{
    dp[0] = 1;
    cin>>s; int len = s.length();
    for(int i = 0; i < len; ++i){
        if(s[i]=='l') dp[1]+=dp[0];
        else if(s[i]=='o') dp[2]+=dp[1];
        else if(s[i]=='v') dp[3]+=dp[2];
        else if(s[i]=='e') dp[4]+=dp[3];
    }
    cout<<dp[4]<<endl;
    return 0;
}
