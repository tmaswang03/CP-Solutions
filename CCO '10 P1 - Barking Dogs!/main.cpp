#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
const ll MM = 1e3+10;
using namespace std;
vector<int>v[MM];
int D, F, T, a,b, w[MM], cnt[MM], dst[MM], nxt[MM], nt;
priority_queue<pii, vector<pii>, greater<pii> > pq;
int main()
{
    cin>>D; ms(nxt, -1); nxt[1] = 0;
    for(int i = 1; i <= D; ++i){
        cin>>w[i];
    }
    cin>>F;
    while(F--){
        cin>>a>>b; v[a].pb(b);
    }
    cin>>T;
    for(int i = 0; i <= T; ++i){
        for(int j = 1; j <= D; ++j){
            if(nxt[j]==i){
                ++cnt[j];
                for(auto && k : v[j]){
                    nt = i + w[k];
                    if(i > nxt[k]) nxt[k] = nt;
                }
            }
        }
    }
    for(int i = 1; i <= D; ++i){
        cout<<cnt[i]<<endl;
    }
    return 0;
}
