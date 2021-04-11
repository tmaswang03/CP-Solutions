#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
string opera = "+-*/%";
bool isop(char c){
    for(int i = 0; i < opera.length(); ++i){
        if(c==opera[i]) return 1;
    }
    return 0;
}
int ret(char c, int x, int y){
    if(c=='+') return x+y;
    if(c=='-') return x-y;
    if(c=='*') return x*y;
    if(c=='/') return x/y;
    if(c=='%') return x%y;
}
int main()
{
    for(int t = 0; t < 5; ++t){
        stack<int>st;
        string s; getline(cin, s);
        if(isop(s[0])){
            for(int i = s.length()-1; i >= 0; --i){
                if(s[i]!=' '){
                    if(isop(s[i])){
                        int x = st.top(); st.pop();
                        int y = st.top(); st.pop();
                        st.push(ret(s[i], x, y));
                    }
                    else{
                        st.push(s[i]-'0');
                    }
                }
            }
        }
        else{
            for(int i = 0; i < s.length(); ++i){
                if(s[i]!=' '){
                    if(isop(s[i])){
                        int x = st.top(); st.pop();
                        int y = st.top(); st.pop();
                        st.push(ret(s[i], y, x));
                    }
                    else{
                        st.push(s[i]-'0');
                    }
                }
            }
        }
        int res = st.top(); st.pop(); cout<<res<<endl;
    }
    return 0;
}
