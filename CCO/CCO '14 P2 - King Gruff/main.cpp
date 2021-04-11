#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
typedef long long ll;
const ll INF = 0x3f3f3f3f;
char _;
using namespace std;


// edges in tree = vertices - 1
bool myComparison(const tuple<int, int, int, int, int> &a,const tuple<int, int, int ,int, int> &b)
{
       return get<0>(a)<get<0>(b);
}

bool cmp(ll n, const tuple<int, int, int, int, int> &a)
{
    // For instance...
    return get<0>(a)>=n;
}

vector <pair<int, int> > v[100001];
vector <pair<int, int> > v2[100001];
tuple<int, int, int, int, int> arr[100001]; // node1,node2, dist, shutcost, mindist
ll pfsum[100002];

void sp (int src, vector<pair<int, int> >adj[], ll dist[]) {
    queue<pair<int, int> >q;
	q.push({src,0});
	dist[src] = 0;
	while (!q.empty()) {
		int temp = q.front().first;
		int temp1 = q.front().second;
		q.pop();
		if(temp1>dist[temp]) continue;
		for(auto && i : adj[temp]){
            if(temp1+i.second<dist[i.first]){
                dist[i.first]=temp1+i.second;
                q.push({i.first,temp1+i.second});
            }
		}
	}
}


int main() {
  int N, M, A, B; gc(N); gc(M); gc(A); gc(B);
  for(int i = 0; i < M; ++i){
    int a,b,c,d; gc(a); gc(b);gc(c); gc(d); // firstnode, secondnode, length, shutcost
    v[a].push_back({b,c});
    v2[b].push_back({a,c});
    arr[i]={0,a,b,c,d};
  }
  ll dist[100001];
  ll dist2[100001];
  ms(dist2,INF);
  ms(dist,INF);
  sp(A,v,dist);
  sp(B,v2,dist2);
  // for(int i = 0; i <= M; ++i){
  //   printf("%i,",dist[i]);
  // }
  for(int i = 0; i < M; ++i){
    get<0>(arr[i])=dist[get<1>(arr[i])]+dist2[get<2>(arr[i])]+get<3>(arr[i]);
  }
  // printf("%i, %i\n",A,B);
  sort(arr, arr + M, myComparison);
//   for(int i =0 ; i < M; ++i){
//     printf("%i %i %i %i  %i\n",get<0>(arr[i]),get<1>(arr[i]),get<2>(arr[i]),get<3>(arr[i]),get<4>(arr[i]));
//   }
  pfsum[0]=get<4>(arr[0]);
  for(int i = 1; i <= M; ++i){
    pfsum[i]=pfsum[i-1]+get<4>(arr[i]); // pfsum[i] = sum to [i]
  }
//  for(int i = 0; i < M; ++i){
//    printf("%lld, ",pfsum[i]);
//  }
  int qe; gc(qe);
  for(int i =0 ; i < qe; ++i){
    int D; gc(D);
    ll temp1 = upper_bound(arr, arr + M , make_tuple(D,INF,INF,INF,INF)) - arr ;
    if(temp1==0){
        printf("0\n");
    }
    else{
        printf("%lld\n",pfsum[temp1-1]);
    }
  }
  return 0;
}
