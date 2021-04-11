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
const ll MAXN = 1e6+1;
using namespace std;
bool arr[MAXN];

int main()
{
    int N; scan(N);
    for(int i = 0; i < N; ++i){
        char c; cin>>c;
        arr[i] = int(c-'0');
    }
    int counter = 0;
    for(int i = N-1; i >= 0; --i){
        if((arr[i]+counter)&1) ++counter;
    }
    cout<<counter<<endl;
    return 0;
}
