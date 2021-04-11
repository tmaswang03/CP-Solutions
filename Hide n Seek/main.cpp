#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define ms(a,b)  memset(a,b,sizeof(a));

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int N,M,T; cin>>N>>M>>T;
  pair<int, int>hiders[6];
  int hidecount;
  bool visited[21][21];
  vector<pair<int,int> >v[21][21];
  ms(visited,false);
  char arr[21][21];
  int sx,sy;
  for(int r = 0; r < N; ++r){
    for(int c = 0; c < M; ++c){
      char a; cin>>a;
      arr[c][r]=a;
      if(a=='X'){
        visited[c][r]=true;
      }
      else if(a=='G'){
        sx=c;
        sy=r;
      }
      else if(a=='H'){
        hiders[hidecount].first=c;
        hiders[hidecount].second=r;
        ++hidecount;
      }
    }
  }
  for(int i = 0 ; i < N; i++){
      for(int j = 0; j < M; j++){
          if(visited[j][i]==false){
              if(i-1>=0 && visited[j][i-1]==false){
                  v[j][i].push_back(make_pair(j,i-1));
              }
              if(j-1>=0 && visited[j-1][i]==false){
                  v[j][i].push_back(make_pair(j-1,i));
              }
              if(i+1<N && visited[j][i+1]==false){
                  v[j][i].push_back(make_pair(j,i+1));
              }
              if(j+1<M && visited[j+1][i]==false){
                  v[j][i].push_back(make_pair(j+1,i));
              }
          }
      }
  }
  sort(hiders,hiders+T);
  int finaldist=0x3f3f3f;
  do{
    queue<pair<int, int> >q;
    int dist[21][21];
    ms(dist,0x3f3f3f);
    dist[sx][sy]=0;
    ms(visited,false);
    visited[sx][sy]=1;
    q.push({sx,sy});
    int counter=0;
    while(counter<T){
      while(!q.empty()){
        int temp = q.front().first;
        int temp1= q.front().second;
        q.pop();
        for(pair<int, int> i: v[temp][temp1]){
          if(visited[i.first][i.second]==false){
            dist[i.first][i.second]=dist[temp][temp1]+1;
            q.push({i.first,i.second});
            visited[i.first][i.second]=true;
          }
        }
      }
        q.push({hiders[counter].first,hiders[counter].second});
        int tempdist=dist[hiders[counter].first][hiders[counter].second];
        ms(dist,0x3f3f3f);
        ms(visited,false);
        visited[hiders[counter].first][hiders[counter].second]=1;
        dist[hiders[counter].first][hiders[counter].second]=tempdist;
        ++counter;
    }
    if(dist[hiders[T-1].first][hiders[T-1].second]<finaldist){
      finaldist=dist[hiders[T-1].first][hiders[T-1].second];
    }
  } while(next_permutation(hiders,hiders+T));
  cout<<finaldist<<endl;

  return 0;
}
