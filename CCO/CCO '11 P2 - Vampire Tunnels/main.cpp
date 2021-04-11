#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;


void gc(int &number)
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
int dist[1601][3601];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
  int K,N,E; cin>>K>>N>>E;
  vector<tuple<int, int, int> >paths[N];
  for(int i = 0; i < E; i++){
    int a,b,c,d; cin>>a>>b>>c>>d;
    paths[a].push_back(make_tuple(b,c,d));
    paths[b].push_back(make_tuple(a,c,d));
  }
  memset(dist,0x3f,sizeof(dist));
  queue<pair<int,int> >q;
  q.push({0,0});
  dist[0][0]=0;
  while(!q.empty()){
    int temp=q.front().first;
    int temp1=q.front().second;
    q.pop();
    for(auto && i: paths[temp]){
        if(get<2>(i)==0){
            if(dist[temp][temp1]+get<1>(i)<dist[get<0>(i)][temp1]){
                dist[get<0>(i)][temp1]=dist[temp][temp1]+get<1>(i);
                q.push({get<0>(i),temp1});
            }
        }
        else{
            if(dist[temp][temp1]+get<1>(i)<dist[get<0>(i)][temp1+get<1>(i)]&&temp1+get<1>(i)<=K){
                dist[get<0>(i)][temp1+get<1>(i)]=dist[temp][temp1]+get<1>(i);
                q.push({get<0>(i),temp1+get<1>(i)});
            }
        }
    }
  }
  int ssp=0x3f3f3f;
  for(int i = K; i>=0; --i){
    if(dist[N-1][i]<ssp){
        ssp=dist[N-1][i];
    }
  }
  if(ssp==0x3f3f3f){
    cout<<"-1"<<endl;
  }
  else{
    cout<<ssp<<endl;
  }
  return 0;
}
