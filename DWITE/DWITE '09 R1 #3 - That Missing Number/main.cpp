#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef  unsigned long long ull;
typedef long long ll;
using namespace std;

int main()
{
    unordered_map<int, int>freq;
    for(int i = 0; i < 5; ++i){
        int M; scan(M);
        bool vis[M+2];
        ms(vis,0);
        for(int k = 0; k < M; ++k){
            int a; scan(a);
            vis[a] = 1;
        }
        for(int i = 1; i <= M+1; ++i){
            if(!vis[i]){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
