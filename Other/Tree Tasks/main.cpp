#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
const int MAXN = 5e5+1;
using namespace std;
int arr1[MAXN], arr2[MAXN], N, pre[MAXN], cost[MAXN];
vector<pair<int, int> >v[MAXN];

void dfsmax(int node1, int parent, int arr1[]){
    for(auto && i : v[node1]){
        if(i.first!=parent){
            arr1[i.first]=arr1[node1]+i.second;
            pre[i.first] = node1;
            cost[i.first] = i.second;
            dfsmax(i.first, node1, arr1);
        }
    }
}

int main()
{
    scan(N);
    for(int i = 0; i < N-1; ++i){
        int a, b, c; scan(a); scan(b); scan(c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfsmax(1,-1,arr1);
    int diameter = 0, ind = 0, temp1 = arr1[1], radius = 0x3f3f3f3f;
    for(int i = 1; i <= N; ++i){
        if(arr1[i]>diameter){
            ind =i; diameter = arr1[i];
        }
    }
    ms(arr1,0);
    int tempind = ind;
    dfsmax(ind,-1,arr1);
    for(int i = 1; i <= N; ++i){
        if(arr1[i] > diameter){
            ind = i; diameter = arr1[i];
        }
    }
    for(int x = 0; ind != tempind; ind = pre[ind] ){
        radius = min(radius, max(x, diameter - x));
        x+=cost[ind];
    }
    printf("%i\n",diameter);
    printf("%i\n",radius);
    return 0;
}
