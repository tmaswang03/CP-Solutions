#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;

using namespace std;



int main() {
  vector<pair <int,int> >multiples[1000001];
  for(int i = 1; i < 1001; ++i){
    for(int j = 1; j < 1001; ++j){
      multiples[j*i].push_back(make_pair(i, j));
    }
  }
  int roomval[1001][1001];
  int m, n; gc(m); gc(n);
  for(int i = 1; i <= m; ++i){
    for(int j= 1; j<= n; ++j){
      int a; gc(a);
      roomval[i][j]=a;
    }
  }
  queue<pair<int, int> >q;
  bool visited[1001][1001];
  q.push({1,1});
  memset(visited, false, sizeof(visited));
  visited[1][1]=true;
  while(!q.empty()){
    int temp = q.front().first;
    int temp1= q.front().second;
    q.pop();
    for(pair<int, int> i:multiples[roomval[temp][temp1]]){
      if(i.first==m&&i.second==n){
        printf("yes\n");
        exit(0);
      }
      if(!visited[i.first][i.second] && i.first<=m && i.second <=n){
        q.push({i.first,i.second});
        visited[i.first][i.second]=1;
      }
    }
  }
  printf("no\n");
  return 0;
}
