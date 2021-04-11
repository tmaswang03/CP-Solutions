#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int a,b, temp, temp1; cin>>a>>b;
    int xcoord,ycoord;
    int xcoord1,ycoord1;
    char paths [1000][1000];
    int dist[1000][1000] = {0};
    vector<pair<int,int> >vpaths[a+1][b+1];
    cin>>xcoord>>ycoord;
    cin>>xcoord1>>ycoord1;
     for(int i = 0 ; i < a; i++){
    for(int j = 0; j < b; j++){
      char x;
      cin>>x;
      paths[i][j]=x;
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

  int withouttel=dist[xcoord1][ycoord1];
  int tels; cin>>tels;
  memset(dist,0,sizeof(dist));
  memset(visited,false,sizeof(visited));
  pair<int, int> tellies[tels];
  for(int i = 0 ; i < tels; i++){
    int xc,yc;cin>>xc>>yc;
    vpaths[xc][yc].push_back(make_pair(xcoord1,ycoord1));
    tellies[i].first=xc;
    tellies[i].second=yc;
  }

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
  int withtel=dist[xcoord1][ycoord1];
  if(withouttel-withtel==0){
    cout<<"0"<<endl;
  }
  else{
  cout<<withouttel-withtel+1<<endl;
  }
  return 0;
}
