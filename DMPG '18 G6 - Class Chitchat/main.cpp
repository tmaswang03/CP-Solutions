#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f;
using namespace std;
char _;
int cost[MAXN], dist[MAXN];
vector<int> v[MAXN], v2[MAXN];
int main()
{
    int N,C,K; scan(N); scan(C); scan(K); ms(dist, INF);
    for(int i = 1; i <= N; ++i){
        scan(cost[i]);
    }
    for(int i = 1; i <= N; ++i){
        int c; scan(c);
        for(int j = 0; j < c; ++j){
            int a; scan(a); v[i].pb(a); v2[a].pb(i);
        }
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1}); dist[1] = 0;
    while(!pq.empty()){
        int temp1 = pq.top().first, temp2 = pq.top().second; //distance;
        pq.pop();
        if(temp1>dist[temp2]) continue;
        for(auto && i : v[temp2]){
            for(auto && j : v2[i]){
                if(dist[temp2]+K+abs(cost[j]-cost[temp2])<dist[j]){
                    dist[j] = dist[temp2]+K+abs(cost[j]-cost[temp2]);
                    pq.push({dist[j],j});
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        printf(dist[i]>=INF ? "-1\n" : "%d\n", dist[i]);
    }
    return 0;
}
