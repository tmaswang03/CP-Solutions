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
const ll MM = 1e3+10;
using namespace std;
int psa[MM][MM], n, q, x1, x2, z1, z2; char c;
int main()
{
    cin>>n>>q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin>>c;
            if(c=='*') psa[i][j] = 1;
            psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    while(q--){
        cin>>x1>>z1>>x2>>z2;
        cout<<psa[x2][z2]-psa[x2][z1-1]-psa[x1-1][z2]+psa[x1-1][z1-1]<<endl;
    }
    return 0;
}
