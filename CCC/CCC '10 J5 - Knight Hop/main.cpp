#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int temp, temp1;
    vector<pair<int,int> > boardarr[8][8];
    for(int i = 0 ; i < 8; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(i-1>=0 &&j+2<=7){
            boardarr[i][j].push_back(make_pair(i-1,j+2));
            }
            if(i-1>=0 &&j-2>=0){
            boardarr[i][j].push_back(make_pair(i-1,j-2));
            }
            if(i+1<=7&&j-2>=0){
            boardarr[i][j].push_back(make_pair(i+1,j-2));
            }
            if(i+1<=7 &&j+2<=7){
            boardarr[i][j].push_back(make_pair(i+1,j+2));
            }
            if(i+2<=7 &&j-1>=0){
            boardarr[i][j].push_back(make_pair(i+2,j-1));
            }
            if(i+2<=7 && j+1<=7){
            boardarr[i][j].push_back(make_pair(i+2,j+1));
            }
            if(i-2>=0 &&j-1>=0){
            boardarr[i][j].push_back(make_pair(i-2,j-1));
            }
            if(i-2>=0 &&j+1<=7){
            boardarr[i][j].push_back(make_pair(i-2,j+1));
            }
        }
    }
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int dist[8][8];
    queue <pair<int,int> >q;
    bool visited[8][8]= {false};
    visited[a-1][b-1]=true;
    dist[a-1][b-1]=0;
    q.push(make_pair(a-1,b-1));
    while(!q.empty()){
        temp=q.front().first;
        temp1=q.front().second;
        q.pop();
        for(pair<int,int>i:boardarr[temp][temp1]){
           if(!visited[i.first][i.second]){
            visited[i.first][i.second]=true;
            q.push(make_pair(i.first,i.second));
            dist[i.first][i.second]=dist[temp][temp1]+1;
           }
        }
    }
    cout<<dist[c-1][d-1]<<endl;

    return 0;
}
