#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
int n, m;
string s; char a, b;
map<char, char> mep;
int main()
{
    cin>>n>>m;
    for(int i = 0; i < 26; ++i){
        mep[char('a'+i)] = char('a'+i);
    }
    cin>>s;
    while(m--){
        cin>>a>>b;
        for(int i = 0; i < 26; ++i){
            if(mep[char('a'+i)]==a){
                mep[char('a'+i)]=b;
            }
            else if(mep[char('a'+i)]==b){
                mep[char('a'+i)]= a;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout<<mep[s[i]];
    }
    return 0;
}
