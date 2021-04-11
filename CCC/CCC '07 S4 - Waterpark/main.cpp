#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;


int dist[10000]={0};
bool visited[10000]={false};
void dfs(int node, vector<int> graph[], int n){
    for (int x:graph[node]){
        if (!visited[x]) {
          dfs(x,graph,n);
          dist[node]+=dist[x];
        }
        else{
          dist[node]+=dist[x];
        }
      visited[node]=1;
    }
}

int main() {
  int n; cin>>n;  dist[n]=1; visited[n]=1;
  vector <int> slides[n+1];
  for(;;){
    int a,b; cin>>a>>b;
    if(a==0||b==0){
      break;
    }
    else{
      slides[a].push_back(b);
    }
  }
  dfs(1,slides,n);
  cout<<dist[1]<<endl;
  return 0;
}
