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
int a[MM], len, last; string S;
int main()
{
    cin>>S; len = S.length();
    for(int i = 1; i < len; ++i){
        if(S[i]!='A' && S[i-1]!='A'){
            cout<<S.substr(last, i-last)<<" ";
            last = i;
        }
        else if(S[i]=='A' && S[i-1]=='A'){
            cout<<S.substr(last, i-last)<<" ";
            last = i;
        }
    }
    cout<<S.substr(last, len-last)<<endl;
    return 0;
}