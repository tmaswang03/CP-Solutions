#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;


void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

}

int main() {
cin.tie(0);
cin.sync_with_stdio(0);
vector <int> heights[1000000];
bool visited[1000000];
memset(visited, false, sizeof(visited));
queue <int> q;
int h, c; fastscan(h);fastscan(c);
for(int i = 0 ; i < c; i++){
  int a,b;fastscan(a);fastscan(b);
  heights[a].push_back(b);
}
int a,b;fastscan(a);fastscan(b);
bool agb,bga;
agb=0;
bga=0;
int temp;
q.push(a);
while(!q.empty()){
  temp=q.front();
  q.pop();
  for(auto && i:heights[temp]){
    if(i==b){
      agb=true;
      }
      if(!visited[i]){
        q.push(i);
        visited[i]=1;
      }
    }
    if(agb==true){
        cout<<"yes"<<endl;
        exit(0);
      }
    }


q.push(b);
while(!q.empty()){
  temp=q.front();
  q.pop();
  for(auto && i:heights[temp]){
    if(i==a){
      bga=true;
    }
      if(!visited[i]){
        q.push(i);
        visited[i]=1;
      }
  }
  if(bga==true){
    cout<<"no"<<endl;
    exit(0);
      }
  }



cout<<"unknown"<<endl;


  return 0;
}
