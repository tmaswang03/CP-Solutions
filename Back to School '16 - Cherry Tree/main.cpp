#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int cherries[10001];
  int N,C,K;cin>>N>>C>>K;
  for(int i = 1; i <=N; i++){
    int c; cin>>c;
    cherries[i]=c;
  }
  vector<pair<int,int> >branchesw[N+1];
  for(int i = 0 ; i < N-1; i++){
    int a,b,n;cin>>a>>b>>n;
    branchesw[a].push_back({b,n});
  }
  queue<int>q;
  int counter =  0;
  for(int i = 1; i <=N; i++){
      for(pair<int, int>k:branchesw[i]){
            q.push(k.first);
            int totalc=cherries[k.first];
            int totalw=k.second;
            while(!q.empty()){
               int temp = q.front();
                q.pop();
                for(pair<int, int>j:branchesw[temp]){
                  totalc+=cherries[j.first];
                  totalw+=j.second;
                  q.push(j.first);
                }
      }
      if(totalc>=C && totalw <=K){
        counter++;
      }
    }
  }
  cout<<counter<<endl;
  return 0;
}
