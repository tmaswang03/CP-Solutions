#include <iostream>
#include <queue>
using namespace std;
vector <int> heights[1000000];
queue <int> q; int h, c, a, b, temp; bool agb,bga;
int main() {
    cin>>h>>c;
    for(int i = 0 ; i < c; i++){
        cin>>a>>b;
        heights[a].push_back(b);
    }
    cin>>a>>b;
    q.push(a);
    while(!q.empty()){
        temp=q.front(); q.pop();
        for(auto && i:heights[temp]){
            if(i==b) agb = 1;
            q.push(i);
            }
        }
    q.push(b);
    while(!q.empty()){
        temp=q.front(); q.pop();
        for(auto && i:heights[temp]){
            if(i==b) bga=1;
            q.push(i);
            }
        }
    if(agb==1) cout<<"yes"<<endl;
    else if(bga==1) cout<<"no"<<endl;
    else cout<<"unkown"<<endl;
}
