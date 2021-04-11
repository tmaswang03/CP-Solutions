#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
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
const ll lg2 = 12, MM = 1e3+10, inf = 1e9+1;
using namespace std;
int sparse[lg2][lg2][MM][MM], logs[MM], N, sz = 1, psz;
void init(std::vector<std::vector<int>> arr){
    logs[1] = 0; N = arr[0].size();
    for(int i = 2; i < MM; ++i) logs[i] = logs[i>>1] + 1;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j) sparse[0][0][i][j] = arr[i][j];
    for(int lg = 1; lg < lg2; ++lg){
        psz = 1<<(lg-1);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N-sz; ++j){
                sparse[0][lg][i][j] = min(sparse[0][lg-1][i][j], sparse[0][lg-1][i][j+psz]);
            }
        }
    }
    for(int i = 1; i < lg2; ++i){
        sz = 1<<(i-1);
        for(int r = 0; r < N-sz; ++r){
            for(int j = 0; j < lg2; ++j){
                for(int c = 0; c < N; ++c){
                    sparse[i][j][r][c] = min(sparse[i-1][j][r][c], sparse[i-1][j][r+sz][c]);
                }
            }
        }
    }
}
int query(int a, int b, int c, int d){
    int kx = logs[b-a+1], ky = logs[d-c+1];
    int r1 = min (sparse[kx][ky][a][c], sparse[kx][ky][a][d+1-(1<<ky)]);
    int r2 = min(sparse[kx][ky][b+1-(1<<kx)][c], sparse[kx][ky][b+1-(1<<kx)][d+1-(1<<ky)]);
    return min(r1, r2);
}
int main()
{
    return 0;
}
