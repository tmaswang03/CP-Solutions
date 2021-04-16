#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e2+10;
using namespace std;
int s[MM], worst = 0, cur;
pair<int, int> top;
vector<pair<int, int> >v[MM];
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            cin>>cur; s[j]+=cur;
            v[i].pb({cur, j});
        }
    }
    for(int i = 0; i <  n; ++i){
        if(s[i]>top.s){
            top.s = s[i]; top.f = i;
        }
    }
    for(int i = 0; i < k; ++i){
        sort(v[i].begin(),  v[i].end(), greater<pair<int, int> >());
        for(int it = 0; it < n; ++it){
            if(v[i][it].s==top.f) worst = max(worst, it);
        }
    }
    cout<<"Yodeller "<<top.f+1<<" is the TopYodeller: score "<<top.s<<", worst rank "<<worst+1<<endl;
    return 0;
}
