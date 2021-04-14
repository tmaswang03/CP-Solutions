#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int a,b, temp, temp1; cin>>a>>b;
  int xcoord,ycoord;
  int xcoord1,ycoord1;
  char paths [1000][1000];
  int dist [1000][1000] = {0};
  vector<pair<int,int> >vpaths[a+1][b+1];
  for(int i = 0 ; i < a; i++){
    for(int j = 0; j < b; j++){
      char x;
      cin>>x;
      paths[i][j]=x;
      if(x=='s'){
        xcoord=i;
        ycoord=j;
      }
      else if(x=='e'){
          xcoord1=i;
          ycoord1=j;
      }
    }
  }
  for(int i = 0;  i < a; i++){
    for(int j = 0 ; j < b; j++){
      if(paths[i][j]!='X'){
        if(i-1>=0 && paths[i-1][j]!='X'){
          vpaths[i][j].push_back(make_pair(i-1,j));
        }
        if(j-1>=0 && paths[i][j-1]!='X'){
          vpaths[i][j].push_back(make_pair(i,j-1));
        }
        if(i+1<a && paths[i+1][j]!='X'){
          vpaths[i][j].push_back(make_pair(i+1,j));
        }
        if(j+1<b && paths[i][j+1]!='X'){
          vpaths[i][j].push_back(make_pair(i,j+1));
        }
      }
    }
  }
  queue<pair<int,int> >q;
  bool visited [1000][1000] = {false};
  dist[xcoord][ycoord]=0;
  q.push(make_pair(xcoord, ycoord));
  while(!q.empty()){
    temp=q.front().first;
    temp1=q.front().second;
    q.pop();
    for(pair<int, int>i : vpaths[temp][temp1]){
      if(visited[i.first][i.second]==false){
        visited[i.first][i.second]=true;
        dist[i.first][i.second]=dist[temp][temp1]+1;
        q.push(make_pair(i.first,i.second));
      }
    }
  }
  if(dist[xcoord1][ycoord1]==0){
    cout<<-1<<endl;
  }
  else{
    cout<<dist[xcoord1][ycoord1]-1<<endl;
  }

  return 0;
}
