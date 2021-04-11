#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;
int main() {
  int t; cin>>t;
  for(int i = 0 ; i < t; ++i){
    char grid[20][20];
    int a,b; cin>>a>>b;
    int dist[20][20]={0};
    bool visited[20][20]={false};
    queue<pair<int, int> >q;
    vector<pair<int,int> > paths[a][b];
    for(int r = 0; r < a; ++r){
      for(int c = 0; c < b; c++){
        char x; cin>>x;
        grid[r][c]=x;
      }
    }
    for(int r = 0; r < a; ++r){
      for(int c = 0; c < b; c++){
        if(grid[r][c]=='+'){
          if(r-1>=0 && grid[r-1][c]!='*'){
            paths[r][c].push_back(make_pair(r-1,c));
          }
          if(c-1>=0 && grid[r][c-1]!='*'){
            paths[r][c].push_back(make_pair(r,c-1));
          }
          if(r+1<a && grid[r+1][c]!='*'){
            paths[r][c].push_back(make_pair(r+1,c));
          }
          if(c+1<b && grid[r][c+1]!='*'){
            paths[r][c].push_back(make_pair(r,c+1));
          }
        }
        else if(grid[r][c]=='|'){
          if(r-1>=0 && grid[r-1][c]!='*'){
            paths[r][c].push_back(make_pair(r-1,c));
          }
          if(r+1<a && grid[r+1][c]!='*'){
            paths[r][c].push_back(make_pair(r+1,c));
          }
        }
        else if(grid[r][c]=='-'){
          if(c-1>=0  && grid[r][c-1]!='*'){
            paths[r][c].push_back(make_pair(r,c-1));
          }
          if(c+1<b && grid[r][c+1]!='*'){
            paths[r][c].push_back(make_pair(r,c+1));
          }
        }
      }
    }
    q.push(make_pair(0,0));
    dist[0][0]=1;
    visited[0][0]=true;
    int temp, temp1;
    while(!q.empty()){
      temp=q.front().first;
      temp1=q.front().second;
      q.pop();
      for(pair<int,int>i : paths[temp][temp1]){
        if(visited[i.first][i.second]==false){
          visited[i.first][i.second]=true;
          dist[i.first][i.second]=dist[temp][temp1]+1;
          q.push(make_pair(i.first,i.second));
        }
      }
    }
    if(dist[a-1][b-1]==0){
      cout<<"-1"<<endl;
    }
    else{
      cout<<dist[a-1][b-1]<<endl;
    }
  }
  return 0;
}
