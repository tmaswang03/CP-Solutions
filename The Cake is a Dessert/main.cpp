#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 5e3+2;
using namespace std;
ll pfsum[MAXN][MAXN], diff[MAXN][MAXN], arr[MAXN][MAXN];
int main()
{
    int N,M,K; scan(N); scan(M); scan(K); // N columns, M rows
    ms(pfsum, 0); ms(diff, 0);
    for(int i = 0; i < K; ++i){
        int x,y,X,Y; scan(x); scan(y); scan(X); scan(Y);
        diff[x][y]+=1; diff[x][Y+1]-=1; diff[X+1][y]-=1;
        diff[X+1][Y+1]+=1;
    }
    for(int r = 1; r <= N; ++r){
        for(int c = 1; c <= M; ++c){
            pfsum[r][c]=pfsum[r-1][c]+pfsum[r][c-1]-pfsum[r-1][c-1]+diff[r][c];
        }
    }
    for(int r = 1; r <= N; ++r){
        for(int c = 1; c <= M; ++c){
            pfsum[r][c]+=pfsum[r-1][c]+pfsum[r][c-1]-pfsum[r-1][c-1];
        }
    }
    int Q; scan(Q);
    for(int i = 0; i < Q; ++i){
        int a,b,c,d; scan(a); scan(b); scan(c); scan(d); //
        cout<<pfsum[c][d]-pfsum[c][b-1]-pfsum[a-1][d]+pfsum[a-1][b-1]<<endl;
    }
    return 0;
}
