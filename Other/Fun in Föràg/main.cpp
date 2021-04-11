#include<bits/stdc++.h>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
#define ms(a,b) memset(a,b,sizeof(a));
using namespace std;

ll dist[100001];



int main() {

  ll N,M; gc(N); gc(M);
  vector<tuple<int, int, int> >v[N+1];
  ll A,B,C;
  for(int i = 0; i < M; ++i){
    ll a,b, c; gc(a); gc(b); gc(c);
    v[a].push_back({b,c,i});
    v[b].push_back({a,c,i});
  }
  gc(A); gc(B); gc(C);
  ll a = 0, b = M;
  ll temp = LLONG_MAX;
  while(a<=b){
    ll i = (a+b)/2;
    ms(dist,0x3f);
    priority_queue<pair<ll,ll>, vector<pair<ll, ll> >,greater<pair<ll,ll> > >q;
    q.push({0,A});
    dist[A]=0;
    while(!q.empty()){
      ll temp = q.top().second;
      ll temp1 = q.top().first;
      q.pop();
      if(temp1>dist[temp]) continue;
      for(auto && k: v[temp]){
        if(get<2>(k)<=i && dist[temp]+get<1>(k)<dist[get<0>(k)]){
          dist[get<0>(k)]=dist[temp]+get<1>(k);
          q.push({temp1+get<1>(k),get<0>(k)});
        }
      }
    }
    if(dist[B]<=C){
      temp = min(temp,(ll)i);
      b = i-1;
    }
    else{
        a = i+1;
    }
  }
  printf(temp>=LLONG_MAX ? "-1\n" : "%lld\n",temp+1);



  return 0;
}
