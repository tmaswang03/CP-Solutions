#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
char _;
int R, C, err[2], tot, mask, dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}}, p[14]; string s; double dp[2][1594323];
void decode(int g[], int mask){
    int p = R*C - 1;
    for(int i=R-1; i>=0; i--)
        for(int j=C-1; j>=0; j--)
            g[p--] = mask % 3, mask/=3;
}
double fun(int u, int mask){
    if(dp[u][mask] >= 0) return dp[u][mask];
    vector<double> prob;
    int g[14]; decode(g, mask);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            int cur = i*C + j;
            if(g[cur] != u + 1) continue;
            for(int k=0; k<4; k++){
                int nr = i + dir[k][0], nc = j + dir[k][1], nxt = nr*C + nc;
                if(nr >=0 && nr < R && nc>=0 && nc<C && g[nxt]){
                    int nmask = mask - g[cur]*p[tot-cur-1] - g[nxt]*p[tot-nxt-1] + g[cur]*p[tot-nxt-1];
                    prob.push_back(1 - fun(!u, nmask));
                }
            }
        }
    }
    sort(prob.begin(), prob.end(), greater<double>());
    double ret = 0.0;  int sz = min((int)prob.size(), err[u]);
    if(sz == 0) return dp[u][mask] = 0.0;
    for(int i=0; i<sz; i++) ret += prob[i];
    return dp[u][mask] = ret/sz;
}
int main(){
    cin >> R >> C; tot=R*C; fill_n(dp[0], 2*1594323, -1.0);
    p[0] = 1;
    for(int i=1; i<tot; i++) p[i] = p[i-1] * 3;
    for(int i=0; i<R; i++){
        cin >> s;
        for(int j=0; j<C; j++){
            int val = s[j] == 'J'? 1: (s[j]=='D'? 2: 0);
            mask = mask*3 + val;
        }
    }
    cin >> err[0] >> err[1];
    printf("%.3f\n", fun(0, mask));
}
