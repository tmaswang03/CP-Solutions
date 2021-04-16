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
int N;
bool dstnct = 0, vis[10];
bool ye(int N){
    ms(vis, 0);
    string s = to_string(N);
    for(char c : s){
        if(vis[c-'0']) return 0;
        vis[c-'0'] = 1;
    }
    return 1;
}
int main()
{
    cin>>N;
    while(!dstnct){
        ++N;
        if(ye(N)) dstnct = 1;
    }
    cout<<N<<endl;
    return 0;
}
