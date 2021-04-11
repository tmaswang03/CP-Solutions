#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
  int N,M,T;cin>>N>>M>>T;
  vector<int> rooms[N+1];
  for(int i = 0 ; i < M; i++){
    int a,b; cin>>a>>b;
    rooms[a].push_back(b);
  }
  int Q,temp; cin>>Q;

  for(int i = 0 ; i < Q; i++){
    long long dist[1001];
    bool visited[1001];
    memset(dist, 0x3f, sizeof(dist));
    memset(visited, false, sizeof(visited));
    int a,b; cin>>a>>b;
    dist[a]=0;
    queue<int>q;
    q.push(a);
    while(!q.empty()){
      temp=q.front();
      q.pop();
      for(auto && i: rooms[temp]){
        if(visited[i]==false){
          visited[i]=true;
          dist[i]=dist[temp]+T;
          q.push(i);
          if(i==b){
            while(!q.empty()){
              q.pop();
            }
          }
        }
      }
    }
    string str1= "Not enough hallways!";
    if(dist[b]<0x3f3f3f){
      cout<<dist[b]<<endl;
    }
    else{
      cout<<str1<<endl;
    }

  }
  return 0;
}
