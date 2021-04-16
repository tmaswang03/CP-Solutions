#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define fscan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{
    char x, y;
    bool arr[27][27];
    ms(arr,0);
    for(;;){
        cin>>x>>y;
        if(x!='*'){
            arr[x-'A'][y-'A']=1;
            arr[y-'A'][x-'A']=1;
        }
        else{
            int counter =0;
            for(int i = 0; i < 26; ++i){
                for(int j = i+1; j < 26; ++j){
                    bool visited[26];
                    ms(visited,0);
                        if(arr[i][j]==1){
                            arr[i][j]=0;
                            arr[j][i]=0;
                            queue<int>q;
                            q.push(0);
                            visited[0]=1;
                            while(!q.empty()){
                                int temp1 = q.front();
                                q.pop();
                                for(int k = 0; k < 26; ++k){
                                    if(arr[temp1][k] && !visited[k]){
                                        visited[k]=1;
                                        q.push(k);
                                    }

                            }
                        }
                        if(!visited[1]){
                            ++counter;
                            char x = (char)('A'+i);
                            char y = (char)('A'+j);
                            cout<<x<<y<<endl;
                        }
                        arr[i][j]=1;
                        arr[j][i]=1;
                    }
                }
            }
            cout<<"There are "<<counter<<" disconnecting roads."<<endl;
            break;
        }
    }
    return 0;
}
