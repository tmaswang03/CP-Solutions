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
ll res = 0, len, cntl[30], cntr[30]; string str;
ll check(){
    int cnt = 0;
    for(int i = 0; i < 26; ++i){
        if(cntl[i]&&cntr[i])++cnt;
    }
    return cnt;
}
int main()
{
    cin>>len>>str;
    for(int i = 0; i < len; ++i){
        ++cntr[str[i]-'a'];
    }
    for(int i = 0; i < len; ++i){
        ++cntl[str[i]-'a']; --cntr[str[i]-'a'];
        res = max(res, check());
    }
    cout<<res<<endl;
    return 0;
}
