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
string str, vow = "aeiouy";
int main()
{
    for(;;) {
        cin>>str; int N = str.length();
        if(str == "quit!") return 0;
        else {
            if(N <= 4) cout<<str<<endl;
            else {
                if(str.substr(N - 2, 2) == "or" && vow.find(str[N - 3]) == string::npos) {
                    cout<<str.substr(0, N - 2) + "our"<<endl;
                }
                else cout<<str<<endl;
            }
        }
    }
    return 0;
}