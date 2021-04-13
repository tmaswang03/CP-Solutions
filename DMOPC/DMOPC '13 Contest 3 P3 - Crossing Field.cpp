#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main() {
  int N,H; cin>>N>>H;
  int pathsarr[1500][1500];
  vector<pair<int, int> >paths[N][N];
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j< N; j++){
      int a; cin>>a;
      pathsarr[i][j]=a;
    }
  }
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j< N; j++){
      if(i-1>=0){
        if(abs(pathsarr[i-1][j]-pathsarr[i][j])<=H){
          paths[i][j].push_back(make_pair(i-1,j));
      }
    }
      if(j-1>=0){
        if(abs(pathsarr[i][j-1]-pathsarr[i][j])<=H){
          paths[i][j].push_back(make_pair(i, j-1));
      }
    }
      if(i+1<N){
        if(abs(pathsarr[i+1][j]-pathsarr[i][j])<=H){
          paths[i][j].push_back(make_pair(i+1, j));
      }
    }
      if(j+1<N){
        if(abs(pathsarr[i][j+1]-pathsarr[i][j])<=H){
          paths[i][j].push_back(make_pair(i, j+1));
      }
    }

  }
  }
  bool visited[1500][1500]={false};
  queue<pair<int, int> >q;
  q.push(make_pair(0, 0));
  visited[0][0]=true;
  int temp,temp1;
  while(!q.empty()){
    temp=q.front().first;
    temp1=q.front().second;
    q.pop();
    for(pair<int, int> i: paths[temp][temp1]){
      if(visited[i.first][i.second]==false){
        q.push(make_pair(i.first, i.second));
        visited[i.first][i.second]=true;
      }
    }
  }
  if(visited[N-1][N-1]==true){
    cout<<"yes"<<endl;
  }
  else{
    cout<<"no"<<endl;
  }
  return 0;
}
