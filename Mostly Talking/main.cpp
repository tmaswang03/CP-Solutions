#include<bits/stdc++.h>
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef int ll;
const int INF=0x3f3f3f;
using namespace std;


vector<pair<ll, ll> >v[500001];

vector<pair<ll, ll> >v2[500001];
ll arr[500001];
ll arr2[500001];




int main()
{
    ll N,M; cin>>N>>M;
    for(int i = 0; i < M; ++i){
        ll a, b,c; cin>>a>>b>>c;
        v[a].push_back({b,c});
        v2[b].push_back({a,c});
        //node , weight
    }
    int D; cin>>D;
    queue<int>q;
    q.push(1); // current distance, node
    ms(arr,INF);
    arr[1]=0;
    bool visited[500001];
    ms(visited,false);
    while(!q.empty()){
        ll temp1 = q.front();
        q.pop();
        visited[temp1]=false;
        for(auto && i : v[temp1]){
            if(arr[temp1]+i.second<arr[i.first]){
                arr[i.first]=arr[temp1]+i.second;
                if(!visited[i.first]){
                    q.push(i.first);
                    visited[i.first]=1;
                }
            }
        }
    }
    ms(arr2,INF);
    arr2[N]=0;
    q.push(N);
    ms(visited,false);
    while(!q.empty()){
        ll temp2 = q.front(); //curr dist, node
        q.pop();
        visited[temp2]=false;
        for(auto && i : v2[temp2]){ //i.first=node i.second=cost
            if(arr2[temp2]+i.second<arr2[i.first]){
                arr2[i.first]=arr2[temp2]+i.second;
                if(!visited[i.first]){
                    q.push(i.first);
                    visited[i.first]=1;
                }
            }
        }
    }
//    for(int i = 1; i <= N; ++i){
//        printf("%d ",arr[i]);
//    }printf("\n");
//
//    for(int i = 1; i <= N; ++i){
//        printf("%d ",arr2[i]);
//    }printf("\n");

    ll min1 = arr[N];
    for(int i = 0; i < D; ++i){
        ll a,b,c; cin>>a>>b>>c;
        min1=min(min1,arr[a]+arr2[b]+c);
        // 4 3 1 2 5 2 3 5 3 4 5
        //2 1 3 15
        //2 1 2 15
    }
    if(min1>=INF){
        printf("-1\n");
    }
    else{
        printf("%d\n",min1);
    }
//    printf("%lld\n",arr[N]);
    return 0;
}
