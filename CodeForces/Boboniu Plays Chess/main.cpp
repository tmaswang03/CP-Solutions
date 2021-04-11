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
using namespace std;

int main()
{
    int N, M, R, C, viscounter = 0; scan(N); scan(M); scan(R); scan(C);
    bool visited[N+1][M+1]; ms(visited, 0);
    visited[R][C] = 1;
    visited[R][1] = 1;
    cout<<R<<" "<<C<<endl;
    cout<<R<<" "<<1<<endl;
    //r = N, c = m
    for(int r = 1; r <= M; ++r){
        if(r%2==0){
            for(int c = 1; c <= N; ++c){
                if(!visited[c][r]){
                    visited[c][r] = 1;
                    cout<<c<<" "<<r<<endl;
                }
            }
        }
        else{
            for(int c = N; c>=1; --c){
                if(!visited[c][r]){
                    visited[c][r] = 1;
                    cout<<c<<" "<<r<<endl;
                }
            }
        }
    }
    return 0;
}
