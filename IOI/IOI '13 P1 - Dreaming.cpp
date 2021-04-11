#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
ll const MAXN = 1e5+1;
using namespace std;
bool visited[MAXN];
vector<pair<int, int> >v[MAXN];
vector<int>minvis;
int diameter = 0, radius = 0, ind = 0, parent[MAXN], cost[MAXN];

inline void dfsmax(int node1, int par,int length = 0){
    visited[node1]=1;
//    cout<<node1<<endl;
    if(length > diameter){
      ind = node1;
      diameter = length;
    }
    for(auto && i : v[node1]){
        if(i.first!=par){
            parent[i.first] = node1;
            cost[i.first] = i.second;
            dfsmax(i.first, node1, length+i.second);
        }
    }
}


// A = First point, B = Second Point, T = Time Taken,
// Returns Diameter
// find trees and the diameter of each tree
// case1 sol = max1radius + max2radius + L (i think) or a diameter,
// case2 = max2radius + max3radius + 2L, all paths are connected to the centroid of the biggest island
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    ms(visited,0);
    int ans = 0;
    for(int i = 0; i < M; ++i){
        v[A[i]].pb({B[i],T[i]});
        v[B[i]].pb({A[i],T[i]});
    }
    vector<int>radi;
    for(int i = 0; i < N; ++i){
        if(!visited[i]){
            diameter = 0, ind = i, radius = 0x3f3f3f;
            dfsmax(i, -1, 0);
            int tempind = ind;
            diameter = 0;
            dfsmax(ind, -1, 0);
            if(ind != tempind){
                for(int x = 0; ind != tempind; ind = parent[ind]){
                    radius = min(radius, max(x, diameter - x));
                    x+=cost[ind];
                }
            }
            else{
                radius = 0;
            }
//            cout<<arr1[2]<<" "<<arr2[2]<<endl;
            radi.pb(radius);
            ans = max(ans,diameter);
//            cout<<i<<" "<<radius<<endl;
        }
    }
    sort(radi.begin(),radi.end(),greater<int>());
    if(radi.size()>=2) ans = max(ans, radi[0]+radi[1]+L);
    if(radi.size()>=3) ans = max(ans, radi[1]+radi[2]+L+L);
    return ans;
}

int main()
{
    /*
12 8 2
0 8 4
8 2 2
2 7 4
5 11 3
5 1 7
1 3 1
1 9 5
10 6 3
*/
    int N,M,L, A[MAXN], B[MAXN], T[MAXN];
    scan(N); scan(M); scan(L);
    for(int i = 0; i < M; ++i){
        int a,b,c; scan(a); scan(b); scan(c);
        A[i]=a; B[i]=b; T[i]=c;
    }
    cout<<travelTime(N,M,L,A,B,T);
    return 0;
}
