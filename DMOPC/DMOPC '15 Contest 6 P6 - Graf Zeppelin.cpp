#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
int main() {
  int N,M,K; cin>>N>>M>>K;
  vector<int>v[N+1];
  for(int i = 0; i < M; ++i){
    int a,b; cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
    int dist[1501];
    bool visited[1501];
    ms(dist,0);
    ms(visited,false);
  for(int i = 1; i <= N; ++i ){
    queue<int>q;
    if(visited[i]==0){
        q.push(i);
        visited[i]=1;
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto && k : v[temp]){
            dist[k]++;
            if(!visited[k]){
                visited[k]=1;
                q.push(k);
            }
        }
    }
  }
  for(int i = 1; i <=N; ++i){
    cout<<dist[i]+1<<endl;
  }
  return 0;
}
