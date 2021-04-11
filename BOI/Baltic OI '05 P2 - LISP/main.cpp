#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
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
int N, M, oc, cc, sc, cnt;
string s, tmp, out;
//idea : everything is just 1 bracket except for final one which is the amount of brackets left over;
// impossible only if at a point more ) brackets than ( brackets
int main()
{
    cin>>N>>M;
    while(s.length()!=N){
        cin>>tmp; s+=tmp;
    }
    for(int i = 0; i < N; ++i){
        if(s[i]=='(') ++oc;
        else if(s[i]==')') ++cc;
        else ++sc;
        if(s[i]==']' && sc!=M){ out+="1\n"; ++cnt;}
        if(cc+sc>oc){cout<<0<<"\n"; return 0;}
    }
    cout<<1<<"\n";
    cout<<out;
    cout<<oc-cc-cnt<<"\n";
    return 0;
}
