#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;

using namespace std;

int main()
{
    int x, y; scan(x); scan(y);
    int dist[100001];
    ms(dist,0x3f3f3f);
    dist[x]=0;
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int temp1=q.front();
        q.pop();
        if(temp1*2<=100000 && dist[temp1]+1<dist[2*temp1]){
            q.push(2*temp1);
            dist[2*temp1]=dist[temp1]+1;
        }
        if(temp1+1<=100000 && dist[temp1]+1<dist[temp1+1]){
            q.push(temp1+1);
            dist[temp1+1]=dist[temp1]+1;
        }
        if(temp1-1>=0 && dist[temp1]+1<dist[temp1-1]){
            q.push(temp1-1);
            dist[temp1-1]=dist[temp1]+1;
        }
    }
    printf("%i\n",dist[y]);
    return 0;
}
