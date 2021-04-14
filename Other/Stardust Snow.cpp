#include<bits/stdc++.h>
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
const ll MAXN = 300;
using namespace std;
struct snow{
    int T, V, c, r; // temperature, value, column,
};
snow v[60][60];
int dp[60][60][60][60]; // time, snowflakes, temperature,  position]
int R,C,S,B,K,M;
int recur(int time, int sno, int temp, int pos) {
    int res = dp[time][sno][temp][pos];
    if (res!=-1) return res;
    if (temp >= B || time > R || sno > K) return dp[time][sno][temp][pos] = 0;
    res = 0;
    for (int mv=0; mv<=M; ++mv) {
        if (pos + mv > C)  break;
        res = max(res, recur(time + 1, sno, temp, pos+mv));
        if (v[time][pos + mv].T + temp < B){
          res = max(res, v[time][pos + mv].V + recur(time + 1, sno + 1 , temp + v[time ][pos + mv].T, pos + mv));
        }
    }
    for (int mv=0; mv<=M; ++mv) {
        if (pos - mv <= 0)  break;
        res = max(res, recur(time + 1, sno, temp, pos-mv));
        if (v[time][pos - mv].T + temp < B){
          res = max(res, v[time][pos - mv].V + recur(time + 1, sno + 1 , temp + v[time ][pos - mv].T, pos - mv));
        }
    }
    return dp[time][sno][temp][pos] = res;
}
int main()
{
    scan(R); scan(C); scan(S); scan(B); scan(K); scan(M);
    ms(dp, -1);
    for(int c1 = 0; c1 <= C; ++c1){
        for(int r1 = 0; r1 <= R; ++r1){
            v[c1][r1] = {0,0,0,0};
        }
    }
    for(int i = 0; i < S; ++i){
        int T, V, c1, r1; scan(T); scan(V); scan(c1); scan(r1);
        v[r1-1][c1] = {T,V,c1,r1};
    }
    cout<<recur(0,1,0,0)<<endl;
    return 0;
}
