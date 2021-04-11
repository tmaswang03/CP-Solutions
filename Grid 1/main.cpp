#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
const ll mod = 1000000007;
using namespace std;

ll dist[1000][1000];
bool visited[1000][1000];
vector<pair<int, int> >graph[1000][1000];
void dfs(int x,int y){
    for (auto && it:graph[x][y]){
            if(!visited[it.first][it.second]){
                dfs(it.first,it.second);
            }
            dist[x][y]+=dist[it.first][it.second];
            if(dist[x][y]>=mod){
                dist[x][y]%=mod;
            }
        }
        visited[x][y]=1;
    }

int main()
{
    ms(dist,0);
    ms(visited,false);
    int x,y; gc(x); gc(y);
    dist[x-1][y-1]=1;
    int arr[1000][1000];
    for(int i = 0; i < y; ++i){
        for(int j = 0; j < x; ++j){
            char c; cin>>c;
            if(c=='.'){
                arr[j][i]=0;
            }
            else{
                arr[j][i]=1;
            }
        }
    }
    for(int i = 0; i < y; ++i){
        for(int j = 0; j < x; ++j){
            if(arr[j][i]==0){
                if(j+1<x&&arr[j+1][i]!=1){
                    graph[j][i].push_back({j+1,i});
                }
                if(i+1<y&&arr[j][i+1]!=1){
                    graph[j][i].push_back({j,i+1});
                }
            }
        }
    }
    dfs(0,0);
    printf("%ll\n",dist[0][0]);
    return 0;
}
