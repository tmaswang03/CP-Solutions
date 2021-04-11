#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;
typedef int ll;
vector <pair<int, int> >v[20001];
int main()
{
    int N, M; gc(N); gc(M);
    for(int i = 0; i < M; ++i){
        int x, y, z; gc(x); gc(y); gc(z);
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
     queue<pair<ll,ll> >q; //node,dist
    pair<ll, ll>dist[20001]; //min time and 2nd best time
    ms(dist,0x3f3f3f);
    q.push({1,0});
    pair<int, int>gay;
    gay.first=-1;
    gay.second=-1;
    while(!q.empty()){
        int temp = q.front().first;
        int temp2= q.front().second;
        q.pop();
        if(temp2>dist[temp].second) continue;
        for(auto && i : v[temp]){
            if(temp2+i.second<dist[i.first].first){
                dist[i.first].second=dist[i.first].first;
                dist[i.first].first=temp2+i.second;
                q.push({i.first,i.second+temp2});
                //printf("%i %i\n",i.first,i.second+temp2);
            }
            else if (temp2+i.second < dist[i.first].second && temp2+i.second!=dist[i.first].first){
                //printf("%i %i\n",i.first,i.second+temp2);
                dist[i.first].second = temp2+i.second;
                q.push({i.first,i.second+temp2});
            }
            if(i.first==N && gay.first==-1){
              gay.first=i.second+temp2;
            }
            else if (i.first==N && i.second+temp2!=gay.first && gay.first!=-1){
              gay.second=i.second+temp2;
            }
        }
    }
    printf(gay.second==-1? "-1\n" : "%lld\n",dist[N].second);
    return 0;
}
