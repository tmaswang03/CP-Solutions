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

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll p1 = 1, p2 = 2e9;
    for(;;){
        ll i = (p2+p1)/2;
        cout<<i<<endl;
        string s; cin>>s;
        if(s=="SINKS") p1 = i+1;
        else if (s=="FLOATS") p2 = i-1;
        else break;
    }
    return 0;
}
