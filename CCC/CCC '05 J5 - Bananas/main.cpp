#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
string s;
bool recur(string s){
    cout<<s<<endl;
    if(s.empty()) return 1;
    if(s[0]=='A' && s.length()>1) return recur(s.substr(1, s.length()-1));
    else if(s[0]=='A' && s.length()<= 1) return 1;
    else if(s[0]=='N' && s.length()>1) return recur(s.substr(1, s.length()-1));
    else if(s[0] =='N' && s.length()<=1) return 0;
    else if(s[0]== 'B'){
        int pt = 0;
        if(s.length()<=2) return 0;
        while(s[pt]!='S' && pt <s.length()-1){
            ++pt;
        }
        if(pt == s.length()-1 && s[pt]!='S') return 0;
        else if(pt == s.length()-1 && s[pt]=='S') return recur(s.substr(1, s.length()-2));
        else return recur(s.substr(pt+1, s.length()-pt-1));
    }
    else return 0;
}
int main()
{
    boost();
    for(;;){
        cin>>s;
        if(s=="X") return 0;
        if(recur(s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
