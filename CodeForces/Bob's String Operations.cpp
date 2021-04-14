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
string s, t;
int mep[27];
bool used[27], possible = 1;
int main()
{
    boost(); ms(used, 0);
    for(int i = 0; i < 27; ++i){
        mep[i] = i;
    }
    cin>>s>>t;
    for(int i = 0; i < s.length(); ++i){
        int scur1 = s[i]-'a', tcur = t[i]-'a';
        scur1 = mep[scur1];
        if(scur1 != tcur){
            mep[scur1] = tcur; mep[tcur] = scur1;
        }
    }
    for(int i = 0; i < s.length(); ++i){
        s[i] = mep[s[i]]+'a';
    }
    cout<<s<<endl;
    if(s==t){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
