#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e3+10, seed = 131;
using namespace std;
string a[MM];
ll hsh[MM][MM], p[MM];
int main()
{
    int N, M; scan(N); scan(M); ms(hsh, 0);
    p[0] = 1;
    for(int i = 1; i <= N; ++i){
        cin>>a[i];
        for(int j = 1; j <= a[i].length(); ++j){
            hsh[i][j]=hsh[i][j-1]*seed+(a[i][j-1]-'0'+1);
            p[j] = p[j-1]*seed;
        }
    }

    return 0;
}
