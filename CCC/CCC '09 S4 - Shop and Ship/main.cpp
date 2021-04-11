#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;


int main()
{
    int N; gc(N);
    vector<pair<int,int> >c[N+1];
    int T; gc(T);
    for(int i = 0; i < T; ++i){
        int a,b,co; gc(a);gc(b);gc(co);
        c[a].push_back({b,co});
        c[b].push_back({a,co});
    }
    int K; gc(K);
    int mincost=0x3f3f3f;
    unordered_map<int,int>umap;
    for(int i = 0; i < K; ++i){
        int a,b; gc(a); gc(b);
        umap[a]=b;
    }
    int d; gc(d);
    queue<int>q;
    int distc[5001];
    ms(distc,0x3f);
    distc[d]=0;
    q.push(d);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto && a: c[temp]){
            if(distc[temp]+a.second<distc[a.first]){
                distc[a.first]=distc[temp]+a.second;
                q.push(a.first);
            }
        }
    }
    for(auto&&i:umap){
        if(distc[i.first]+i.second<mincost){
            mincost=distc[i.first]+i.second;
        }
    }

printf("%i",mincost);
    return 0;
}
