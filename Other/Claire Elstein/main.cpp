#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAXN = 100001;
char _;
using namespace std;
ll dist[MAXN], dist2[MAXN];
bool in[MAXN], out[MAXN];
vector<int>v[MAXN];
int N,M;

int main()
{
    scan(N); scan(M);
    ms(in, 1);
    ms(out, 1);
    ms(dist,0);
    for(int i = 0; i < M; ++i){
        int a,b; scan(a); scan(b);
        in[b]=0; out[a]=0;
        v[a].push_back(b);
    }
    queue<int>q;
    bool inq[MAXN];
    ms(inq, 0);
    for(int i = 1; i <= N; ++i){
        if(in[i]){
            q.push(i);
            dist[i]=1;
            while(!q.empty()){
                int temp1 = q.front();
                q.pop();
                inq[temp1]=0;
                for(auto && e: v[temp1]){
                    dist[e]+=dist[temp1];
                    dist[e]%=MOD;
                    if(!inq[e]){
                        inq[e]=1;
                        q.push(e);
                    }
                }
            }
        }
    }
    return 0;
}
