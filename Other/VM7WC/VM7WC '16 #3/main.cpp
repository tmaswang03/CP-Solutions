#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int a,b,c,d; cin>>a>>b>>c>>d;
    bool visited[2000];
    vector<int>v[2000];
    for(int i = 0; i < b; ++i){
        int e,f; cin>>e>>d;
        v[c].push_back(d);
        v[d].push_back(c);
    }
    queue<int>q;
    q.push(c);
    visited[c]=1
    while(!q.empty){
        int temp1 = q.front();
        q.pop();
        for(auto && i : v[temp1]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    printf(visited[d] ? "GO SHAHIR!\n" : "NO SHAHIR!\n");
    return 0;
}
