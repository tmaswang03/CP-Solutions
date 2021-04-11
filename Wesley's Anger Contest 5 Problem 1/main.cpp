#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM =1e3+1;
using namespace std;
vector<int > v[MM];
int a[MM];
int main()
{
    int N, res = 0, counter = -1; scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    sort(a, a+N);
    for(int i = N-1; i >= 0; --i){
        bool placed = 0;
        for(int j = 0; j <= counter; ++j){
            if(v[j].back()>a[i]){
                v[j].pb(a[i]); placed = 1; break;
            }
        }
        if(!placed){
            ++counter;
            v[counter].pb(a[i]);
        }
    }
    for(int i = 0; i <= counter; ++i){
        res+=v[i][0];
    }
    cout<<res<<endl;
    return 0;
}
