#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main()
{
    int r,c,k; cin>>r>>c>>k;
    vector<pair<int, int> >matrix[25][25];
    queue<pair<int,int> >q;
    bool visited[25][25]= {false};
    int paths[25][25] = {{0}};
    int temp,temp1;

    for(int i = 0 ; i < k; i++){
        int a, b; cin>>a>>b;
        visited[b-1][a-1]=true;
    }
    for(int i = 0 ; i < r; i++){
        if(visited[0][i]==true){
          break;
        }
        else{
          paths[0][i]=1;
        }
    }
    for(int i = 0 ; i < c; i++){
      if(visited[i][0]==true){
        break;
      }
      else{
        paths[i][0]=1;
      }
    }
    for(int i = 1; i < c; i++){
      for(int j = 1 ; j < r; j++){
        if(visited[i][j]==false){
          paths[i][j]=paths[i-1][j]+paths[i][j-1];
        }
        else{
          paths[i][j]=0;
        }
      }
    }
    cout<<paths[c-1][r-1]<<endl;

    return 0;
}
