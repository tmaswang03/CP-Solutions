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
const ll MM = 1e5+10;
using namespace std;
pair<int, string> a[MM];
int main()
{
    boost();
    int N; cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i].s>>a[i].f;
    }
    sort(a, a+N);
    cout<<a[N/2].s<<endl;
    return 0;
}
