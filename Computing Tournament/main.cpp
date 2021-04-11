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
typedef unsigned long long ull;
using namespace std;
struct pts{
    int x,y,i;
};

bool fr (pts &a, pts &b){
    return a.x > b.x;
}
bool sr (pts &a, pts &b){
    return a.y > b.y;
}

int main()
{
    vector<pts>v, v2;
    int N, K; scan(N); scan(K);
    for(int i = 1; i <= N; ++i){
        int x,y; scan(x); scan(y);
        v.pb({x,y, i});
    }
    sort(v.begin(), v.end(), fr);
    for(int i = 0; i < K; ++i){
        v2.pb(v[i]);
    }
    sort(v2.begin(), v2.end(), sr);
    cout<<v2[0].i<<endl;
    return 0;
}
