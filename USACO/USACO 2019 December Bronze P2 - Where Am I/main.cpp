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
unordered_set<string>st;
int N; string s;
bool check(int len){
    for(int l = 0; l < s.length()-len+1; ++l){
        if(st.find(s.substr(l, len))!=st.end()) return 0;
        else st.insert(s.substr(l, len));
    }
    return 1;
}
int main()
{
    cin>>N>>s;
    for(int len = 1; len <= s.length(); ++len){
        if(check(len)){cout<<len<<endl; return 0;}
    }
    return 0;
}
