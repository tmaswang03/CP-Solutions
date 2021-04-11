#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef int ll;
typedef long double ld;
using namespace std;
vector<int>v[30000];
int main()
{
    int N,M, doge0,doge1, dist[30000]; scan(N); scan(M);
    ms(dist,0x3f3f3f);
    for(int i = 0; i < M; ++i){
        int x,p; scan(x); scan(p);
        if(!i) doge0=x;
        else if (i==1) doge1=x;
        v[x].push_back(p);
    }
    for(int i = 0; i < N; ++i ){
      sort(v[i].begin(),v[i].end());
      auto last = unique(v[i].begin(),v[i].end());
      v[i].erase(last,v[i].end());
    }
    dist[doge0]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,doge0});
    while(!pq.empty()){
        int temp1=pq.top().first, temp2=pq.top().second; //distance, node
        pq.pop();
        if(dist[temp2]<temp1)continue;
        for(auto && i : v[temp2]){
            for(int j = 1; temp2+j*i<N; ++j){
              if(dist[temp2+j*i]>temp1+j){
                dist[temp2+j*i]=temp1+j;
                  pq.push({dist[temp2+j*i],temp2+j*i});
              }
              if(find(v[temp2+j*i].begin(),v[temp2+j*i].end(),i) != v[temp2+j*i].end()) break;
            }
            for(int j = 1; temp2-j*i>=0; ++j){
              if(dist[temp2-j*i]>temp1+j){
                dist[temp2-j*i]=temp1+j;
                  pq.push({dist[temp2-j*i], temp2-j*i});
              }
              if(find(v[temp2-j*i].begin(),v[temp2-j*i].end(),i) != v[temp2-j*i].end())  break;
            }
        }
    }
    printf(dist[doge1]>=0x3f3f3f ? "-1\n" : "%i\n",dist[doge1]);
    return 0;
}
