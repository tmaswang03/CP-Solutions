#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int n; cin>>n;
  vector <int> friends[10000];
  for(int i = 0 ; i < n; i++){
    int a,b; cin>>a>>b;
    friends[a].push_back(b);
  }
  for(;;){
    int a,b;cin>>a>>b;
    if(a==0||b==0){
      break;
    }
    else{
        int temp;
        int dist[10000]={0};
        queue<int>q;
        q.push(a);
        bool visited[10000]={false};
        visited[a]=true;
        while(!q.empty()){
          temp=q.front();
          q.pop();
          for(auto && i: friends[temp]){
              if(visited[i]==false){
                visited[i]=true;
                dist[i]=dist[temp]+1;
                q.push(i);
              }
          }
        }
        if(dist[b]==0){
          cout<<"No"<<endl;
        }
        else{
          cout<<"Yes "<<dist[b]-1<<endl;
        }
    }
  }
  return 0;
}
