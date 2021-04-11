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
const ll MM = 1e2+10;
using namespace std;
int N, M, W, ant[MM], x, y, route[MM]; vector<int> v[MM];
queue<int>q;
void cover(int s){
    int tmp[MM]; ms(tmp, 0x3f3f3f);
    tmp[s] = 0; q.push(s);
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(auto && i : v[c]){
            if(tmp[c]+4<tmp[i]){
                tmp[i] = tmp[c]+4;
                q.push(i);
            }
        }
    }
    for(int j = 0; j < MM; ++j) ant[j] = min(ant[j], tmp[j]);
}
int main()
{
    scana(N, M); ms(ant, 0x3f3f3f);
    for(int i = 0; i < M; ++i){
        scana(x, y); v[x].pb(y); v[y].pb(x);
    }
    scan(W);
    while(W--){
        scan(x);
        cover(x);
    }
    ms(route, 0x3f3f3f); route[1] = 0;
    q.push(1);
    while(!q.empty()){
        auto c = q.front(); q.pop();
        for(auto && i : v[c]){
            if(route[c]+1 < ant[i] && route[c]+1 < route[i]){
                route[i] = route[c]+1;
                q.push(i);
            }
        }
    }
    if(route[N]>=0x3f3f3f){
        cout<<"sacrifice bobhob314"<<endl;
    }
    else cout<<route[N]<<endl;
    return 0;
}
