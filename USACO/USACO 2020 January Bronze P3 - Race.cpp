#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
ll K, N, sped;
bool valid(double trav, double curs, double maxs){
    double distlft = K-trav;
    if((curs+maxs-1)/2.0*(curs-maxs)>=distlft+maxs) return 0;
    return 1;
}

ll get(ll maxs){
    ll dist = 0, time = 0, curspeed = 0;
    while(dist < K){
        if(valid(dist+curspeed+1, curspeed+1, maxs)) ++curspeed;
        else if (!valid(dist+curspeed, curspeed, maxs)) --curspeed;
        dist+=curspeed; ++time;
    }
    return time;
}
int main()
{
    scan(K); scan(N);
    for(int i = 0; i < N; ++i){
        scan(sped);
        printf("%lld\n", get(sped));
    }
    return 0;
}
