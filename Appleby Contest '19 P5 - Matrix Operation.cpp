#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
const int MAXN = 1501;
typedef long long ll;

using namespace std;
int N;
int arr[MAXN][MAXN];
int dist[MAXN][MAXN]={0};
bool visited[MAXN][MAXN]={false};
void dfs(int x,int y){
  bool nonodes=false;
    if(x+1<N){
        if(arr[x+1][y]>arr[x][y]){
            if(!visited[x+1][y]){
                dfs(x+1,y);
            }
            dist[x][y]=max(dist[x][y],dist[x+1][y]+1);
        }

    }
    if(y+1<N){
        if(arr[x][y+1]>arr[x][y]){
            if(!visited[x][y+1]){
                dfs(x,y+1);
            }
            dist[x][y]=max(dist[x][y],dist[x][y+1]+1);
        }

    }
    if(x-1>=0){
        if(arr[x-1][y]>arr[x][y]){
            if(!visited[x-1][y]){
                dfs(x-1,y);
            }
            dist[x][y]=max(dist[x][y],dist[x-1][y]+1);
        }

    }
    if(y-1>=0){
        if(arr[x][y-1]>arr[x][y]){
            if(!visited[x][y-1]){
                dfs(x,y-1);
            }
            dist[x][y]=max(dist[x][y],dist[x][y-1]+1);
        }

    }
    visited[x][y]=1;
}

int main() {
  scan(N);
  for(int r = 0; r < N; ++r){
    for(int c = 0; c < N; ++c){
        int a; scan(a);
        arr[r][c]=a;
    }
  }
  int res = 0;
  for(int r = 0; r < N; ++r){
    for(int c = 0; c < N; ++c){
        dfs(r,c);
        res = max(res, dist[r][c]);
    }
  }
  cout<<res<<endl;

}
