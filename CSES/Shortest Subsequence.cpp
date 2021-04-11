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
string s, res; int len; bool vis[5];
bool check(){
    for(int i = 0; i < 4; ++i){
        if(!vis[i]) return 0;
    }
    return 1;
}
int gett(char c){
    if(c=='A') return 0;
    if(c=='C') return 1;
    if(c=='G') return 2;
    return 3;
}
int main()
{
    cin>>s; len = s.length();
    for(int i = 0; i < len; ++i){
        vis[gett(s[i])] = 1;
        if(check()){
            ms(vis, 0);
            res.pb(s[i]);
        }
    }
    for(int i = 0; i < 4; ++i){
        if(vis[i]) continue;
        if(i==0) res.pb('A');
        else if(i==1) res.pb('C');
        else if(i==2) res.pb('G');
        else res.pb('T');
        break;
    }
    cout<<res<<endl;
    return 0;
}
