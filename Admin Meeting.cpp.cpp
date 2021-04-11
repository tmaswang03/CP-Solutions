#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
const ll MAXN = 1e3+1;
const ll INF = 0x3f3f3f;
using namespace std;
vector<pair< int, int> >v[MAXN];
int main()
{
    ll to[MAXN], from[MAXN];
    ms(to,INF); ms(from,INF)
    int N,M,T; scan(N); scan(M); scan(T);
    for(int i = 0; i < M; ++i){
        int a,b,c; scan(a); scan(b); scan(c);
        v[a].pb({b,c});
    }
    priority_queue<pair<int,int>, vector<pair<int, int> >,greater<pair<int,int> > >q;
    q.push({0,T});
    to[T] = 0;
    while(!q.empty()){
        int temp1 = q.top().first, temp2 = q.top().second;
        q.pop();
        if(temp1>to[temp2]) continue;
        for(auto && i : v[temp2]){
            if(to[temp2]+i.second < to[i.first]){
                to[i.first] = to[temp2]+ i.second;
                q.push({to[i.first],i.first});
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        ll tempdist[MAXN]; ms(tempdist, INF);
        tempdist[i] = 0;
        q.push({0,i});
        while(!q.empty()){
            int temp1 = q.top().first, temp2 = q.top().second;
            q.pop();
            if(temp1>tempdist[temp2]);
            for(auto && i : v[temp2]){
                if(tempdist[temp2]+i.second < tempdist[i.first]){
                    tempdist[i.first] = tempdist[temp2]+ i.second;
                    q.push({tempdist[i.first],i.first});
                }
            }
        }
        from[i] = tempdist[T];
    }
    ll max1 = 0;
    for(int i = 1; i <= N; ++i){
        max1 = max(max1, to[i]+from[i]);
    }
    cout<<max1<<endl;
    return 0;
}
