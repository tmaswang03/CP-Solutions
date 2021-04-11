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
string happy = ":-)", sad = ":-(", in; int hcnt, scnt;
int main()
{
    getline(cin, in);
    for(int i = 0; i < in.length()-2; ++i){
        if(in.substr(i, 3)==happy) ++hcnt;
        else if(in.substr(i, 3)==sad) ++scnt;
    }
    if(hcnt==scnt && scnt) cout<<"unsure"<<endl;
    else if(hcnt>scnt) cout<<"happy"<<endl;
    else if(scnt>hcnt) cout<<"sad"<<endl;
    else cout<<"none"<<endl;
    return 0;
}
