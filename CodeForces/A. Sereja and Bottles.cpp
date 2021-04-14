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
const ll MM = 1e3+10, MN = 1e2+10;
using namespace std;
int cnt, n, a, b, br[MN], tk[MN];
bool vis[MN];
int main()
{
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a>>b; br[i] = a; tk[i] = b;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i==j) continue;
            if(br[j]==tk[i]) vis[j] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(!vis[i]) ++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}
