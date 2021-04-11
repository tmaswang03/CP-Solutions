#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    int N; scan(N); vector<ld>v;
    for(int i = 0; i < N; ++i){
        int t; scan(t); v.pb(t);
    }
    for(;;){
        int com; scan(com);
        if(!(com^99)){
            int r,p; scan(r); scan(p);
            --r;v.insert(v.begin()+r, v[r]*(ld)p/(ld)100);  v[r+1] = v[r+1]*(ld)((ld)(100-p)/(ld)100);
        }
        else if(!(com^88)){
            int r; scan(r); --r;
            v[r]+=v[r+1]; v.erase(v.begin()+r+1);
        }
        else break;
    }
    for(int i = 0; i < v.size(); ++i) cout<<(int)(round)(v[i])<<" ";

    return 0;
}
