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
const ll MAXN = 1e5+1;
using namespace std;
int psa[MAXN];
vector<int>v;

int main()
{
    int G, P, counter = 0; scan(G); scan(P);
    // always take the higher one
    for(int i = G; i >= 1; --i){
        v.pb(-i);
    }
    for(int i = 0; i < P; ++i){
        int n; scan(n);
        int temp1 = lower_bound(v.begin(), v.end(), -n) - v.begin();
        if(lower_bound(v.begin(), v.end(), -n) == v.end()){
            cout<<i<<endl;
            return 0;
        }
        else{
            ++counter;
            v.erase(v.begin()+temp1);
        }
    }
    cout<<counter<<endl;
    return 0;
}
