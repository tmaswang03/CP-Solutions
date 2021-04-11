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
int n;
string s, t;
int mep1[27], mep2[27];
bool check(string& a, string& b){
    map<char, char> mp;
    for(int i = 0; i < n; i++){
        if(mp.find(a[i]) != mp.end() && mp[a[i]] != b[i]){
            return false;
        }
        mp[a[i]] = b[i];
    }
    return true;
}
int main()
{
    boost();
    cin>>s>>t; ms(mep1, -1); ms(mep2, -1);
    bool pos1 = 1, pos2 = 1;
    for(int i = 0; i < s.length(); ++i){
        int scur = s[i]-'a', tcur = t[i]-'a';
        if(mep1[scur] != -1 && mep1[scur] != tcur){
            pos1 = 0; break;
        }
        mep1[scur] = tcur;
    }
    for(int i = 0; i < t.length(); ++i){
        int scur = t[i]-'a', tcur = s[i]-'a';
        if(mep2[scur] != -1 && mep2[scur] != tcur){
            pos2 = 0; break;
        }
        mep2[scur] = tcur;
    }
    if(pos1 && pos2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
