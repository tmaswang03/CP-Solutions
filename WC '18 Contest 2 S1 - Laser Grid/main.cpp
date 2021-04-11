#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll MM = 2e3+10;
using namespace std;
int N, M, C, v[MM], h[MM], Ox, Oy, x, y;
// question : https://dmoj.ca/problem/wc18c2s1
int main()
{
    cin>>Ox>>Oy>>N>>M>>C;
    // original coordinates of where he falls
    for(int i = 0; i < N; ++i) cin>>v[i];
    for(int i = 0; i < M; ++i) cin>>h[i];
    sort(v, v+N); sort(h, h+M);
    while(C--){
        cin>>x>>y;
        // coordinates of where the gems are
        // the v[i] stretch vertically from coords (v, 0) -> (v, 1000000)
        // h[i] stretches horizontally from coords (0, h) -> (1000000, h);
        // notice : you cannot reach a gem if there exists a vertical line such that
        // Ox< v[i] < x, or x < v[i] < Ox
        // or Oy < h[i] < y or y < h[i] < Oy
        if(Ox < x){
            int idx = upper_bound(v, v+N, Ox) - v;
            if(Ox < v[idx] && v[idx] < x){ cout<<"N"<<endl; continue; }
        }
        else if (x < Ox){
            int idx = upper_bound(v, v+N, x) - v;
            if(x < v[idx] && v[idx] < Ox){ cout<<"N"<<endl; continue; }
        }
        if(Oy < y){
            int idx = upper_bound(h, h+M, Oy) - h;
            if(Oy < h[idx] && h[idx] < y){ cout<<"N"<<endl; continue; }
        }
        else if(y < Oy){
            int idx = upper_bound(h, h+M, y) - h;
            if(y < h[idx] && h[idx] < Oy){ cout<<"N"<<endl; continue; }
        }
        cout<<"Y"<<endl;
     }
    return 0;
}
