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
const ll MM = 1550;
using namespace std;
int h, v, x, y, ans = 0;
set<int> sh, sv; unordered_map<int, int> umap;
int main()
{
    cin>>h>>v;
    for(int i = 0; i < h; ++i){
        cin>>x; sh.insert(x);
    }
    for(int i = 0; i < v; ++i){
        cin>>y; sv.insert(y);
    }
    for(auto && i : sh){
        for(auto && j : sh){
            if(j>=i) break;
            ++umap[i-j];
        }
    }
    // square exists if if horizontal line exists such hy - cy = vx-cv
    // 2 verticals have same distance as 3 horizontal
    for(auto && i : sv){
        for(auto && j : sv){
            if(j>=i) break;
            ans+=umap[i-j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
