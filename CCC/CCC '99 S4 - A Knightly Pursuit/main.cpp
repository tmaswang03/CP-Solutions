#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
const ll MM = 1e2+10, inf = 1e5;
using namespace std;
int N, r, c, mx[4] = {2,1,-2,-1}, my[4] = {2,1,-2,-1};
int dp[MM][MM][MM][MM], opt[MM][MM][MM][MM];
void dfs(int kr, int kc, int pr, int pc){
    int res = dp[kr][kc][pr][pc], curres = -2;
    if(res!=-1) return;
    if(kr == pr && kc == pc){
        opt[kr][kc][pr][pc] = 1;
        dp[kr][kc][pr][pc] = 0;
        return;
    }
    if(kr == pr+1 && kc == pc){
        opt[kr][kc][pr][pc] = 0;
        dp[kr][kc][pr][pc] = 0;
        return;
    }
    if(pr==r && (kr != pr || kc !=pc)){
        opt[kr][kc][pr][pc] = -1;
        dp[kr][kc][pr][pc] = -1;
        return;
    }
    res = inf;
    for(int x = 0; x < 4; ++x){
        for(int y = 0; y < 4; ++y){
            if(abs(mx[x])==abs(mx[y]) || kr+mx[x]<= 0 || kr + mx[x] > r || kc + my[y] <= 0 || kc + my[y] > c) continue;
            dfs(kr+mx[x], kc + my[y], pr+1, pc);
            if(opt[kr+mx[x]][kc + my[y]][pr+1][pc] > curres){
                curres = opt[kr+mx[x]][kc + my[y]][pr+1][pc];
                res = dp[kr+mx[x]][kc + my[y]][pr+1][pc] + 1;
            }
            else if(opt[kr+mx[x]][kc + my[y]][pr+1][pc] == curres){
                res = min(dp[kr+mx[x]][kc + my[y]][pr+1][pc] + 1, res);
            }
        }
    }
    opt[kr][kc][pr][pc] = curres;
    dp[kr][kc][pr][pc] = res;
}
int main()
{
    scan(N);
    while(N--){
        string out;
        ms(opt, -1); ms(dp, -1);
        int pr, pc, kr, kc;
        scana(r, c, pr, pc, kr, kc);
        dfs(kr, kc, pr, pc);
        if(opt[kr][kc][pr][pc]==-1) out = "Loss";
        else if (opt[kr][kc][pr][pc]==0) out = "Stalemate";
        else out = "Win";
        cout<<out<<" in "<<dp[kr][kc][pr][pc]<<" knight move(s)." <<endl;
    }
    return 0;
}
