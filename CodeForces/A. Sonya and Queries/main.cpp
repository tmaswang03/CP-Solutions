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
const ll MM = 1<<19;
using namespace std;
ll bits[MM], N, a;
char opt;
ll convert(ll n){
    string s = to_string(n);
    ll temp = 0;
    for(int i= s.length()-1; i >= 0; --i){
        temp|=((s[i]-'0')%2)<<(s.length()-i-1);
    }
    return temp;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>opt>>a;
        if(opt == '+') ++bits[convert(a)];
        else if (opt == '-') --bits[convert(a)];
        else cout<<bits[convert(a)]<<endl;
    }
    return 0;
}
