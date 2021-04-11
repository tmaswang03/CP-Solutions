#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int dist[100000]={0};
bool visited[100000]={false};
void dfs(int node, vector<int> graph[]){
  bool nonodes=false;
    for (int x:graph[node]){
      nonodes=true;
        if (!visited[x]) {
          dfs(x,graph);
        }
        if(dist[x]>=dist[node]){
          dist[node]=1+dist[x];
        }
      visited[node]=1;
    }
    if(!nonodes){
      dist[node]=0;
      visited[node]=1;
    }
}

int main() {
  int N,M; cin>>N>>M;
  vector<int> v[N+1];
  bool start[100000]={false};
  for(int i = 0; i < M; ++i){
    int a,b; cin>>a>>b;
    v[a].push_back(b);
    start[b]=true;
  }
  int count = 0;
  for(int i = 0; i <=N; ++i){
    if(start[i]==false){
      dfs(i,v);
      if(dist[i]>count){
        count=dist[i];
      }
    }
  }
  cout<<count<<endl;
}
