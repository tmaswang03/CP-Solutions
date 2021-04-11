#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
set<char> op={'+','-','*','/','%'};
bool isop(char c){ return op.find(c)!=op.end();}
double ret(char c, double x, double y){
    if(c=='+') return x+y;
    if(c=='-') return x-y;
    if(c=='*') return x*y;
    if(c=='/') return x/y;
    if(c=='%') return fmod (x,y);
    return pow(x, y);
}
int main()
{
    stack<double>st;
    string s, num; getline(cin, s);
    for(int i = 0; i < s.length(); ++i){
        if(s[i]!=' '){
            if(isop(s[i])){
                double x = st.top(); st.pop();
                double y = st.top(); st.pop();
                st.push(ret(s[i], y, x));
            }
            else{
                while(s[i]!=' '){num+=s[i]; ++i;}
                st.push(stoi(num)); num.clear();
            }
        }
    }
    double res = st.top(); st.pop();
    printf("%f", res);
    return 0;
}
