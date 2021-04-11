#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin>>n>>m;
    vector <pair<int,int> > paths[1001];
    int temp, temp1;
    int dist[1001];
    for(int i = 0 ; i < m; i++){
        int a,b,c;cin>>a>>b>>c;
        paths[a].push_back (make_pair(b,c));
        paths[b].push_back (make_pair(a,c));
    }
    memset(dist,0x3f, sizeof(dist));
    priority_queue<pair<int, int> >djikstras;
    djikstras.push(make_pair(0,1)); dist[1]=0;
    while(!djikstras.empty()){
        temp=djikstras.top().first;
        temp1=djikstras.top().second;
        djikstras.pop();
        for(pair<int,int> i:paths[temp1]){
            if(dist[i.first]>dist[temp1]+i.second){
                dist[i.first]=dist[temp1]+i.second;
                djikstras.push(make_pair(dist[i.first],i.first));
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        printf("%d\n",dist[i]==0x3f3f3f3f?-1:dist[i]);
    }


    return 0;
}
