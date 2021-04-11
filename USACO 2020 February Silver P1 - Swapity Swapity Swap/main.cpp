#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e2+10;
using namespace std;
int N, K, l, r, rep; vector<int> v, o[2];
bool check(int i){
    for(int j = 0; j < o[i].size(); ++j){
        if(o[i][j]!=j) return 0;
    }
    return 1;
}
int main()
{
    scan(N); scan(K);
    for(int i = 0; i < N; ++i){ v.eb(i); o[1].eb(i); o[0].eb(i);}
    for(int i = 0; i < 2; ++i){
        scana(l, r);
        reverse(v.begin() + l-1, v.begin() + r);
    }
    for(int i = 0; i < K; ++i){
        for(int j = 0; j < v.size(); ++j){
            o[i&1][j] = o[!(i&1)][v[j]];
        }
        if(check(i&1)){rep = i+1; break;}
    }
    if(!rep){ for(auto && i : o[(K-1)&1]) cout<<i+1<<endl; return 0;}
    o[0].clear(); o[1].clear();
    for(int i = 0; i < N; ++i){o[1].eb(i); o[0].eb(i);}
    for(int i = 1; i <= K%rep; ++i){
        for(int j = 0; j < v.size(); ++j){
            o[i&1][j] = o[!(i&1)][v[j]];
        }
    }
    for(auto && i : o[(K%rep)&1]) cout<<i+1<<endl;
    return 0;
}
