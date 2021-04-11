#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6+1;
char _;
using namespace std;
int unlucky[maxn];
int main()
{
    int N, K; scan(K);
    for(int i = 0; i < K; ++i){
        scan(unlucky[i]);
    }
    sort(unlucky, unlucky+K);
    scan(N);
    for(int i = 0; i < N; ++i){
        int f; scan(f);
        int temp1 = lower_bound(unlucky, unlucky + K, f) - unlucky;
        cout<<f-temp1<<endl;
    }
    return 0;
}
