#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int main() {
  int N; cin>>N;
  vector<int>pages[N+1];
  int arrends[10001];
  int count=0;
  for(int i = 1 ; i <= N; ++i){
    int a; cin>>a;
    for(int j = 0 ; j < a; j++){
      int b; cin>>b;
      pages[i].push_back(b);
    }
    if(a==0){
      arrends[count]=i;
      ++count;
    }

  }
  bool visited[10001];
  memset(visited, false, sizeof(visited));
  int dist[10001];
  memset(dist,0,sizeof(dist));
  dist[1]=1;
  queue <int> q;
  q.push(1);
  visited[1]=true;
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    for(auto && i: pages[temp]){
      if(!visited[i]){
        visited[i]=1;
        dist[i]=dist[temp]+1;
        q.push(i);
      }
    }
  }
  bool allvis=true;
  for(int i = 1; i <=N; ++i){
    if(visited[i]==0){
      allvis=false;
    }
  }
  if(allvis==1){
    cout<<"Y"<<endl;
  }
  else{
    cout<<"N"<<endl;
  }
  int shortdis=0x3f3f3f;
  for(int i = 0 ; i <count; i++){
    if(dist[arrends[i]]<shortdis && visited[arrends[i]]==true){
      shortdis=dist[arrends[i]];
    }
  }
  cout<<shortdis<<endl;
  return 0;
}
