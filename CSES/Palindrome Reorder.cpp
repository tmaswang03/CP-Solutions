#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
string s; int len, freq[30], od, idx;
void prnt(int cur){
    for(int i = 0; i < freq[cur]/2; ++i) cout<<char(cur+'A');
}
int main()
{
    cin>>s; len = s.length();
    for(int i = 0; i < len; ++i) ++freq[s[i]-'A'];
    for(int i = 0; i < 26; ++i){
        if(freq[i]%2==1){ ++od; idx = i;}
    }
    if(od>1 || (od==1 && len%2==0) ){ cout<<"NO SOLUTION"<<endl; return 0;}
    for(int i = 0; i < 26; ++i){
        if(i!=idx) prnt(i);
    }
    for(int i = 0; i < freq[idx]; ++i) cout<<char(idx+'A');
    for(int i = 25; i >= 0; --i){
        if(i!=idx) prnt(i);
    }
}
