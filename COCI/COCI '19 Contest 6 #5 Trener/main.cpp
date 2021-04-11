#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1e9+7;
using namespace std;
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    ll N, K, res = 0; cin>>N>>K;
    map<string, ll> mp;
    for(int j = 0; j < K; ++j){
        string s; cin>>s; ++mp[s];
    }
    for(int i = 0; i < N-2  ; ++i){
        for(int j = 0; j < K; ++j){
            string s; cin>>s;
            mp[s] += mp[s.substr(0, s.length()-1)] + mp[s.substr(1,s.length()-1)];
            if(s.substr(0,s.length()-1)==s.substr(1,s.length()-1)){
                mp[s]-=mp[s.substr(1,s.length()-1)];
            }
            mp[s]%=mod;
        }
    }
    for(int j = 0; j < K; ++j){
        string s; cin>>s;
        res += mp[s.substr(0, s.length()-1)] + mp[s.substr(1,s.length()-1)];
        if(s.substr(0,s.length()-1)==s.substr(1,s.length()-1)){
                res-=mp[s.substr(1,s.length()-1)];
            }
        res%=mod;
    }
    cout<<res<<endl;
    return 0;
}
