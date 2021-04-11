#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
  int c,r,d; cin>>c>>r>>d;
  vector<pair<int, int> >cityroads[c+1];
  for(int i = 0 ; i < r; i++){
    int x,y,z; cin>>x>>y>>z;
    cityroads[x].push_back({y,z});
    cityroads[y].push_back({x,z});
  }
  int minweight[10001];
  memset(minweight, 0, sizeof(minweight));
  minweight[1]=0x3f3f3f;
  queue<int>q;
  q.push(1);
  int e;
  while(!q.empty()){
  int temp = q.front();
  q.pop();
  for(pair<int, int> i: cityroads[temp] ){
    if(minweight[temp]<i.second && minweight[temp] > minweight[i.first]){
      minweight[i.first]=minweight[temp];
      q.push(i.first);
    }
    else if (minweight[temp]>=i.second && i.second>minweight[i.first]){
      minweight[i.first]=i.second;
      q.push(i.first);
    }
  }
}
int maxweight=0x3f3f3f;
  for(int i = 0 ; i < d; i++){
    int s; cin>>s;
    if (minweight[s] < maxweight){
      maxweight=minweight[s];
    }
  }
  cout<<maxweight<<endl;

  return 0;
}
