#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
using namespace std;

int main()
{
    vector<int>v[10001];
    bool isstart[10001], visited[10001];
    ms(isstart,1);
    int n,m; scan(n); scan(m);
    for(int i = 0; i < m; ++i){
        int a,b; scan(a); scan(b);
        v[a].push_back(b);
        isstart[b]=0;
    }
    for(int i = 1; i <= n; ++i){
        ms(visited,0);
        if(isstart[i]){
            visited[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int temp1=q.front();
                q.pop();
                for(auto && k : v[temp1]){
                    if(!visited[k]){
                        q.push(k);
                        visited[k]=1;
                    }
                }
            }
            printf("gay\n");
            bool source = 1;
            for(int j = 1; j <= n; ++i ){
                if(!visited[j]){
                    source = 0; break;
                }
            }
            if(source){
                printf("Y\n");
                exit(0);
            }

        }
    }
    printf("N\n");

    return 0;
}
