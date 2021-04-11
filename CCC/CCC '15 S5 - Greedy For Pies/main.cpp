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
const ll MAXN = 3e3+10;
const ll MAXM = 1e2+10;
using namespace std;
int pi[MAXN], pi2[MAXM], dp[2][MAXM][MAXM][MAXN], N, M;
// dp states, take the last one?, position, interval
int recur(bool t,int l, int r, int pos){
    int ret = dp[t][l][r][pos];
    if(ret!=-1) return ret;
    ret = 0;
    // if you didn't take previous you can:
    //insert a large pie and take it, take current pie or just continue
    // if you took previous you can, insert small pie as a seperator or just continue.
    if(pos<=N){
        if(!t){
            // insert large pie
            if(l<=r) ret = max(ret,pi2[r]+recur(1, l, r-1, pos));
            // take cur pi
            ret = max(ret, pi[pos]+recur(1, l, r, pos+1));
            // continue
            ret = max(ret, recur(1, l, r, pos));

        }
        else{
            // insert small pie
            if(l<=r) ret = max(ret, recur(0, l+1, r, pos));
            // continue
            ret = max(ret, recur(0,l, r, pos+1));
        }
    }
    else{
        if(l <= r){
            if(!t) ret = max(ret, pi2[r]+recur(1,l,r-1, pos));
            ret = max(ret, recur(0,l+1,r,pos));
        }
    }
    return dp[t][l][r][pos] = ret;
}
int main()
{
    scan(N); ms(dp, -1);
    for(int i = 1; i <= N; ++i)
        scan(pi[i]);
    scan(M);
    for(int i = 1; i <= M; ++i)
        scan(pi2[i]);
    sort(pi2+1, pi2+M+1);
    cout<<recur(0, 1, M, 1)<<endl;
    return 0;
}
