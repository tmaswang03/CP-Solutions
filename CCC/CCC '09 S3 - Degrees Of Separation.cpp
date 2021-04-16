#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define fscan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{
    bool arr[51][51];
    ms(arr,0);
    arr[6][1]=1,arr[6][2]=1,arr[6][5]=1,arr[6][4]=1,arr[6][3]=1,arr[6][7]=1;
    arr[1][6]=1,arr[2][6]=1;
    arr[4][6]=1,arr[4][5]=1,arr[4][3]=1;
    arr[3][4]=1,arr[3][6]=1,arr[3][15]=1,arr[3][5]=1;
    arr[5][6]=1,arr[5][4]=1,arr[5][3]=1;
    arr[7][6]=1, arr[7][8]=1;
    arr[8][7]=1, arr[8][9]=1;
    arr[9][8]=1, arr[9][10]=1,arr[9][12]=1;
    arr[10][11]=1, arr[10][9]=1;
    arr[11][10]=1, arr[11][12]=1;
    arr[12][11]=1, arr[12][9]=1, arr[12][13]=1;
    arr[13][12]=1, arr[13][15]=1, arr[13][14]=1;
    arr[14][13]=1;
    arr[15][13]=1,arr[15][3]=1;
    arr[16][17]=1, arr[16][18]=1, arr[18][16]=1;
    arr[18][17]=1;
    arr[17][18]=1, arr[17][16]=1;
    char s;
    int x, y;
    for(;;){
        cin>>s;
        if(s=='q'){
            break;
        }
        if(s=='i'){
            fscan(x); fscan(y);
            arr[x][y]=1;
            arr[y][x]=1;
        }
        else if(s=='d'){
            fscan(x); fscan(y);
            arr[x][y]=0;
            arr[y][x]=0;
        }
        else if(s=='n'){
            fscan(x);
            int counter = 0;
            for(int i = 0; i <= 50; ++i){
                if(arr[x][i]){
                    ++counter;
                }
            }
            printf("%i\n",counter);
        }
        else if (s=='f'){
            fscan(x);
            int dist[51],counter = 0;
            ms(dist,0x3f);
            queue<pair<int, int> >q;
            dist[x]=0;
            q.push({x,0});
            while(!q.empty()){
                int temp1 = q.front().first;
                int temp2 = q.front().second;
                q.pop();
                for(int i = 0; i <= 50; ++i){
                    if(arr[temp1][i]==1){
                        if(temp2+1<dist[i]){
                            dist[i]=temp2+1;
                            q.push({i,dist[i]});
                        }
                    }
                }
            }
            for(int i = 0; i <= 50; ++i){
                if(dist[i]==2){
                    ++counter;
                }
            }
            printf("%i\n",counter);
        }
        else{
            fscan(x); fscan(y);
            int dist[51];
            ms(dist,0x3f);
            queue<pair<int, int> >q;
            q.push({x,0});
            while(!q.empty()){
                int temp1 = q.front().first;
                int temp2 = q.front().second;
                q.pop();
                for(int i = 0; i <= 50; ++i){
                    if(arr[temp1][i]==1){
                        if(temp2+1<dist[i]){
                            dist[i]=temp2+1;
                            q.push({i,dist[i]});
                        }
                    }
                }
            }
            printf(dist[y]>=0x3f ? "Not connected\n" : "%i\n",dist[y]);
        }
    }

    return 0;
}
