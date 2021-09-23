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
const ll MM = 1e6+10;
using namespace std;
string str; int Q, l, r, chr, psa[MM][30], N; char c;
int main()
{
    getline(cin, str); cin>>Q; N = str.length();
    for(int i = 1; i <= N; ++i){
        if(str[i-1] != ' ') ++psa[i][str[i-1] - 'a'];
    }
    for(int i = 1; i <= str.length(); ++i){
        for(int j = 0; j < 26; ++j) psa[i][j] += psa[i-1][j];
    }
    while(Q--){
        cin>>l>>r>>c; chr = (ll)(c - 'a');
        cout<<psa[r][chr] - psa[l-1][chr]<<endl;
    }
    return 0;
}