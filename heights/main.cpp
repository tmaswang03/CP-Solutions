#include <iostream>
#include <queue>
using namespace std;
int main() {
vector <int> heights[1000000];
queue <int> q;
int h, c; cin>>h>>c;
for(int i = 0 ; i < c; i++){
  int a,b;cin>>a>>b;
  heights[a].push_back(b);
}
int a,b;cin>>a>>b;
bool agb,bga;
int temp;
q.push(a);
while(!q.empty()){
  temp=q.front();
  q.pop();
  for(auto && i:heights[temp]){
    if(i==b){
      agb=true;
    }
    q.push(i);
  }
}
q.push(b);
while(!q.empty()){
  temp=q.front();
  q.pop();
  for(auto && i:heights[temp]){
    if(i==b){
      bga=true;
    }
    q.push(i);
  }
}
if(agb==true){
  cout<<"yes"<<endl;
}
else if(bga==true){
  cout<<"no"<<endl;
}
else{
  cout<<"unkown"<<endl;
}

  return 0;
}
