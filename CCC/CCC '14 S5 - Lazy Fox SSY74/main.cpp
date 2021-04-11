#include <bits/stdc++.h>
#include <iostream>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
char _;

struct E { int u, v, d; };
bool cmp (E a, E b) { return a.d < b.d; }
const int MN = 2003;
int N, x[MN], y[MN], hi[MN], dp[MN], tp[MN];
vector<E> edges;

int main() {
    sc(N);
    for (int i = 1; i <= N; i++) {
        sc(x[i]); sc(y[i]);
        for (int j = 0; j < i; j++)
            edges.pb({j, i, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])});
    }
    sort(edges.begin(), edges.end(), cmp);
    for (E e : edges) {
        if (e.d != hi[e.u]) { hi[e.u] = e.d; tp[e.u] = dp[e.u]; }
        if (e.d != hi[e.v]) { hi[e.v] = e.d; tp[e.v] = dp[e.v]; }
        if(e.u==0) dp[e.u] = max(dp[e.u], tp[e.v]);
        if(e.v==0) dp[e.v] = max(dp[e.v], tp[e.u]);
        if (e.u != 0 && e.v != 0){
            dp[e.v] = max(dp[e.v], tp[e.u] + 1);
            dp[e.u] = max(dp[e.u], tp[e.v] + 1);
        }
    }
    printf("%d\n", dp[0]+1);
}
