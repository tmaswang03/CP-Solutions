#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
// no 3 vowels in a row
// no 3 constanatjat in a row
// atleast 1 L
// bool last letter, 1 = vow, 0 = consonant
ll dp[105][2][2][2];
string vows = "AEIOU", conss = "QWRTYPSDFGHJKLZXCVBNM", s;
ll checkvow(char c){
    if(c=='_') return -1;
    for(int i = 0; i < vows.length(); ++i){
        if(c==vows[i]) return 1;
    }
    return 0;
}
ll recur(int pos, bool hasl, bool lstl, bool scndlstl){
    ll res = dp[pos][hasl][lstl][scndlstl];
    if(res!=-1) return res;
    if(pos>=s.length()) return dp[pos][hasl][lstl][scndlstl] = hasl;
    res = 0;
    if(s[pos]=='_'){
        bool vo = 1, cons = 1;
        if(pos>=2 && lstl && scndlstl) vo = 0;
        if(pos>=1 && pos <s.length()-1 && lstl && checkvow(s[pos+1])==1) vo = 0;
        if(pos <s.length()-2 && checkvow(s[pos+1])==1&&checkvow(s[pos+2])==1) vo = 0;
        if(pos>=2 && !lstl && !scndlstl) cons = 0;
        if(pos>=1 && pos <s.length()-1 && !lstl && checkvow(s[pos+1])==0) cons = 0;
        if(pos <s.length()-2 && checkvow(s[pos+1])==0&&checkvow(s[pos+2])==0) cons  = 0;
        if(cons){
            for(int i = 0; i < conss.length(); ++i){
                if(conss[i]=='L') res+=recur(pos+1, 1, 0, lstl);
                else res += recur(pos+1, hasl, 0, lstl);
            }
        }
        if(vo){
            for(int i = 0; i < vows.length(); ++i){
                res+=recur(pos+1, hasl, 1, lstl);
            }
        }
    }
    else{
        if(s[pos]=='L') res+=recur(pos+1, 1, checkvow(s[pos]), lstl);
        else res+=recur(pos+1, hasl, checkvow(s[pos]), lstl);
    }
    return dp[pos][hasl][lstl][scndlstl] = res;
}

int main()
{
    boost();
    ms(dp,  -1);
    cin>>s;
    cout<<recur(0, 0, 0, 0)<<endl;
    return 0;
}
