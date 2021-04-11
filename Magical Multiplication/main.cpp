#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
ll res = 0;
int main()
{
    boost();
    string a,b; cin>>a>>b;
    for(int i = 0; i < a.length(); ++i){
        int cur = a[i]-'0';
        for(int j = 0; j < b.length(); ++j){
            res+=cur*(b[j]-'0');
        }
    }
    cout<<res<<endl;
    return 0;
}
