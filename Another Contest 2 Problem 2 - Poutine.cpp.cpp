#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
char _;
typedef  unsigned long long ull;
typedef long long ll;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f;
#define pb push_back
using namespace std;

int main()
{
    int N; scan(N);
    vector<int>graph1[N+1], graph2[N+1];
    for(int i = 1; i <= N; ++i ){
        string s; cin>>s;
        for(int j = 0; j < s.length(); ++j){
            if(s[j]=='1'){graph1[i].pb(j+1); graph2[j+1].pb(i);}
        }
    }
    bool visited1[N+1][N+1], visited2[N+1][N+1];
    ms(visited1,true);
    ms(visited2,true);
    for(int i = 1; i <= N; ++i){
        bool tempvis[N+1]; ms(tempvis,false); tempvis[i]=1;
        queue<int>q; q.push(i);
        while(!q.empty()){
            int temp1 = q.front();  q.pop();
            for(auto && it:graph1[temp1]){
                if(!tempvis[it]){ q.push(it); tempvis[it]=1;}
            }
        }
        for(int it = 1; it <= N; ++it){
            if(!tempvis[it]) visited1[i][it]=0;
        }
    }
    for(int i = 1; i <= N; ++i){
        bool tempvis[N+1]; ms(tempvis,false); tempvis[i]=1;
        queue<int>q; q.push(i);
        while(!q.empty()){
            int temp1 = q.front();  q.pop();
            for(auto && it:graph2[temp1]){
                if(!tempvis[it]){q.push(it); tempvis[it] = 1;}
            }
        }
        for(int it = 1; it <= N; ++it){
            if(!tempvis[it]) visited2[i][it]=0;
        }
    }
    int counter = 0;
    for(int i =1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(!visited1[i][j] && !visited2[i][j]) ++counter;
        }
    }
    cout<<counter/2<<endl;
    return 0;
}
