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

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
  int dist[2001][201];
  int K,N,M; gc(K);gc(N);gc(M);
  vector<tuple<int, int, int> >paths[N+1];
  for(int i = 0; i < M; i++){
    int a,b,c,d; gc(a);gc(b);gc(c);gc(d);
    paths[a].push_back(make_tuple(b,c,d));
    paths[b].push_back(make_tuple(a,c,d));
  }
  int A,B; gc(A); gc(B);
  memset(dist,0x3f,sizeof(dist));
  queue<pair<int,int> >q;
  q.push({A,0});
  dist[A][0]=0;
  while(!q.empty()){
    int temp=q.front().first;
    int temp1=q.front().second;
    q.pop();
    for(auto && i: paths[temp]){
        if(dist[temp][temp1]+get<1>(i)<dist[get<0>(i)][temp1+get<2>(i)] && temp1+get<2>(i)<K){
            dist[get<0>(i)][temp1+get<2>(i)]=dist[temp][temp1]+get<1>(i);
            q.push({get<0>(i),temp1+get<2>(i)});
        }
    }
  }
  int ssp=0x3f3f3f;
  for(int i = K; i>=0; --i){
    if(dist[B][i]<ssp){
        ssp=dist[B][i];
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
