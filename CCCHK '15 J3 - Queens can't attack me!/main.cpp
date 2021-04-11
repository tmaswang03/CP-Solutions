#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 300;
using namespace std;
int N, M, x, y, tx, ty, cnt; bool vis[MM][MM];
void mark (int x, int y){
    tx = x; ty = y; vis[x][y] = 1;
    while(tx!=1){
        --tx; --ty;
        vis[tx][ty] = 1;
    }
    tx = x; ty = y;
    while(tx!=1){
        --tx; ++ty;
        vis[tx][ty] = 1;
    }
    tx = x; ty = y;
    while(tx!=N){
        ++tx; ++ty;
        vis[tx][ty] = 1;
    }
    tx = x; ty = y;
    while(tx!=N){
        ++tx; --ty;
        vis[tx][ty] = 1;
    }
    for(int i = 1; i <= N; ++i){
        vis[x][i] = 1; vis[i][y] = 1;
    }
}

int main()
{
    cin>>N>>M;
    while(M--){
        cin>>x>>y; mark(x,y);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(!vis[i][j])++cnt;
        }
    }
//    for(int i = 1; i <= N; ++i){
//        for(int j = 1; j <= N; ++j){
//            if(!vis[i][j]) cout<<0<<" ";
//            else cout<<1<<" ";
//        }cout<<endl;
//    }
    cout<<cnt<<endl;
    return 0;
}
