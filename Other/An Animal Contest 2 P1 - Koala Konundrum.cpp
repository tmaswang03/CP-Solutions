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
int N, freq[30], cnt1, cnt2; string str;
int main()
{
    cin>>N>>str;
    for(int i = 0; i < N; ++i) ++freq[str[i]-'a'];
    for(int i = 0; i < 26; ++i){
        if(freq[i]){
            if(freq[i]%2==0) ++cnt2;
            else ++cnt1;
        }
    }
    cout<<max(cnt1, 1)<<endl;
    return 0;
}