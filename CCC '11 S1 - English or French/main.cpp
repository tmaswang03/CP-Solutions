#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int N, T = 0, S = 0;
string s;
int main()
{
    boost();
    cin>>N;
    for(int i = 0; i <= N; ++i){
        getline(cin, s);
        for(int i = 0; i < s.length(); ++i){
            if(s[i]=='t'||s[i]=='T') ++ T;
            else if(s[i]=='s' || s[i]=='S') ++S;
        }
    }
    if(T > S) cout<<"English"<<"\n";
    else cout<<"French"<<"\n";
    return 0;
}
