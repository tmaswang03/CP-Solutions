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
int m, s, cnt = 0; string res;
int main()
{
    cin>>s>>m;
    if(9*s < m || m == 0){
        cout<<-1<<" "<<-1<<endl; return 0;
    }
    for(int i = 1; i <= s; ++i){
        if(cnt+9+s-i<=m){
            cnt+=9; res.pb('9');
        }
        else{
            int tmp = (m-cnt)-(s-i);
            cnt+=tmp; res.pb('0'+tmp);
        }
    }
    reverse(res.begin(), res.end()); cout<<res<<" "; res = ""; cnt = 0;
    for(int i = 1; i <= s; ++i){
        if(m==cnt) res.pb('0');
        else if(cnt+1+9*(s-i)>=m){
            ++cnt; res.pb('1');
        }
        else{
            int tmp = (m-cnt)%9!=0 ? (m-cnt) - 9*((m-cnt)/9)  : 9;
            cnt+=tmp; res.pb('0'+tmp);
        }
    }
    if(res.back() != '0') reverse(res.begin(), res.end());
    cout<<res<<endl;
    return 0;
}
