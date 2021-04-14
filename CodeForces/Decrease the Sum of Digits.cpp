#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll inf = 1e19;
using namespace std;
ll getsum(ull n){
    ll res = 0; string temp = to_string(n);
    for(int i = 0; i < temp.length(); ++i){
        res+=temp[i]-'0';
    }
    return res;
}
int main()
{
    int t; cin>>t;
    while(t--){
        ll n, s, moves = 0; cin>>n>>s;
        if(getsum(n)<=s){ cout<<0<<endl; continue;}
        for(ull i = 10; i <= n*10; i*=10){
            ull newn = (n/i)*i+i;
            if(getsum(newn)<=s){
                moves = newn-n;
                break;
            }
        }
        cout<<moves<<endl;
    }
    return 0;
}
