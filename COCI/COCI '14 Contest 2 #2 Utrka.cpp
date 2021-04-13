#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost(); cin.tie(0); cin.sync_with_stdio(0);
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
const ll MM = 1e5+10;
using namespace std;
unordered_map<string, int> umap;
int N, vis[MM]; string s, a[MM];
int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; umap[a[i]] = i;
    }
    for(int i = 0; i < N; ++i) ++vis[umap[a[i]]];
    for(int i = 0; i < N-1; ++i){
        cin>>s; --vis[umap[s]];
    }
    for(int i = 0; i < N; ++i){
        if(vis[i]){ cout<<a[i]<<endl; return 0;}
    }
    return 0;
}
