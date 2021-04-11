#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define pb push_back
char _;
typedef int ll;
typedef long double ld;
const ll MAXN = 5e5+1;
using namespace std;
bool pho[MAXN], leaf[MAXN];
int diameter = 0, ind;
vector <int> v[MAXN];
void dfs(int node, int parent){

    for(auto && i : v[node]){
        if(i != parent){
            dfs(i,node);
            if(!leaf[i]) leaf[node] = 0;
            }
        }
    if(pho[node]) leaf[node] = 0;
}

void dia(int node, int parent, int dist){
    if(dist>diameter){
        diameter = dist;
        ind = node;
    }
    for(auto && i : v[node]){
        if(i!=parent && !leaf[i]){
            dia(i,node,dist+1);
        }
    }
}


int main()
{
    ms(pho,0); ms(leaf, 1);
    int N, M, start, counter = 0; scan(N); scan(M);
    for(int i =  0; i < M; ++i){
        scan(start); pho[start] = 1;
    }
    for(int i = 0; i < N-1; ++i){
         int a,b; scan(a); scan(b);
         v[b].pb(a);
         v[a].pb(b);
    }
    dfs(start,-1);
    dia(start,-1,0);
    dia(ind,-1,0);
    for(int i = 0; i < N; ++i){
        if(!leaf[i]) ++counter;
    }
    cout<<2*(counter-1)-diameter<<endl;
    return 0;
}
