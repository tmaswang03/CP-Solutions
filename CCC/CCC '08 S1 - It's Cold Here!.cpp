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
const ll MM = 1e4+10;
using namespace std;
pair<int, string> a[MM];
int cnt = 0, temp;
string str;
int main()
{
    while(str!="Waterloo"){
        cin>>str;
        cin>>temp;
        a[cnt] = {temp, str};
        ++cnt;
    }
    sort(a, a+cnt);
    cout<<a[0].s<<endl;
    return 0;
}
