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
string word;
bool monkey(int l, int r) {
    if(l > r) return 0;
    if(l==r && word[l] == 'A') return 1;
    bool monke = 0;
    for(int i = l+1; i < r; ++i) {
        if(word[i] == 'N') monke|=(monkey(l, i-1) && monkey(i+1, r));
    }
    if(word[l] == 'B' && word[r] == 'S') monke|=(monkey(l+1, r-1));
    return monke;
}
int main()
{
    for(;;) {
        cin>>word;
        if(word == "X") return 0;
        if(monkey(0, word.length() - 1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}