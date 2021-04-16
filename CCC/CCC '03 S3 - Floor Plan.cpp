#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<pair<int,int> >rooms[25][25];
    char floorplan[25][25];
    bool visited[25][25]={false};
    int roomsize[100];
    queue<pair<int, int> >q;
    int temp,temp1;
    int tiles,r,c;cin>>tiles>>r>>c;
    for(int i = 0 ; i < r; i++){
        for(int j = 0 ; j < c; j++){
            char bloc; cin>>bloc;
            floorplan[i][j]=bloc;
            if(bloc=='I'){
                visited[i][j]=true;
            }
        }
    }
    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c; j++){
            if(visited[i][j]==false){
                if(i-1>=0 && visited[i-1][j]==false){
                    rooms[i][j].push_back(make_pair(i-1,j));
                }
                if(j-1>=0 && visited[i][j-1]==false){
                    rooms[i][j].push_back(make_pair(i,j-1));
                }
                if(i+1<r && visited[i+1][j]==false){
                    rooms[i][j].push_back(make_pair(i+1,j));
                }
                if(j+1<c && visited[i][j+1]==false){
                    rooms[i][j].push_back(make_pair(i,j+1));
                }
            }
        }
    }
    int counter,counter1;
    counter = 0;
    for(int i = 0 ; i < r; i++){
        for(int j = 0 ; j < c; j++){
            if(visited[i][j]==false){
                q.push(make_pair(i,j));
                visited[i][j]=true;
                counter1=1;
                while(!q.empty()){
                    temp=q.front().first;
                    temp1=q.front().second;
                    visited[temp][temp1]=true;
                    q.pop();
                    for(pair<int,int>i:rooms[temp][temp1]){
                        if(!visited[i.first][i.second]){
                            visited[i.first][i.second]=true;
                            q.push(make_pair(i.first,i.second));
                            ++counter1;
                        }
                    }
                }
                roomsize[counter]=counter1;
                ++counter;
            }
        }
    }
    sort(roomsize, roomsize + 100, greater<int>());

    int roomcounts=0;
    int i = 0;
    while(roomsize[i]!=0 && i <100 && tiles - roomsize[i]>=0){
      tiles-=roomsize[i];
      ++roomcounts;
      i++;
    }
    if(roomcounts==1){
      cout<<"1 room, "<<"";
    }
    else{
      cout<<roomcounts<<" rooms, "<<"";
    }
    cout<<tiles<<" square metre(s) left over"<<endl;

    return 0;
}
