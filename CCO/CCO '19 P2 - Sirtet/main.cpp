#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
using namespace std;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    int N, M, count1 = 0; cin>>N>>M;
    bool mat[N+10][M+10], vis[N+10][M+10]; int res[N+10][M+10]; ms(mat, 0); ms(vis, 0); ms(res, 0);
    int last[M+1]; ms(last, -1);
    vector<pair<int, int> >v[1000010]; // coords of each item thing
    for(int r = N-1; r >= 0; --r){
        for(int c = 0; c < M; ++c){
            char C; cin>>C;
            if(C=='#'){
                mat[r][c] = 1;
            }
        }
    }
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < M; ++c){
            if(mat[r][c] && !vis[r][c]){
                queue<pair<int, int> >q; q.push({r,c}); vis[r][c] = 1;
                while(!q.empty()){
                    int x = q.front().f,y = q.front().s; q.pop();
                    v[count1].pb({x,y});
                    if(x-1>=0 && mat[x-1][y] && !vis[x-1][y]){
                        q.push({x-1,y}); vis[x-1][y] = 1;
                    }
                    if(x+1 < N && mat[x+1][y] && !vis[x+1][y]){
                        q.push({x+1,y}); vis[x+1][y] = 1;
                    }
                    if(y-1>=0 && mat[x][y-1] && !vis[x][y-1]){
                        q.push({x,y-1}); vis[x][y-1] = 1;
                    }
                    if(y+1 < M && mat[x][y+1] && !vis[x][y+1]){
                        q.push({x,y+1}); vis[x][y+1] = 1;
                    }
                }
                ++count1;
            }
        }
    }
    for(int counter = 0; counter < count1; ++counter){
        int lo = 0, hi = N-1, mid;
        while(hi>lo){
            mid = (hi+lo)/2;
            bool hit = 0;
            for(auto && i : v[counter]){
                if(i.f-mid<0 || res[i.f-mid][i.s]){
                    hit = 1;
                }
            }
            if(!hit){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        for(auto && i : v[counter]){
            res[i.f-mid][i.s] = 1;
        }
    }
    for(int r = N-1; r >= 0; --r){
      for(int c = 0; c < M; ++c){
        if(res[r][c]){
          cout<<"#";
        }
        else cout<<".";
      }cout<<endl;
    }
    return 0;
}
