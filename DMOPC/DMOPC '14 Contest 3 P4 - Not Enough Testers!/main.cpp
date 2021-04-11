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
int arr[MAXN];


int main()
{
    int T, max1 = 0; scan(T);
    int k[T], a[T], b[T];
    for(int i = 0; i < T; ++i){
        scan(k[i]); scan(a[i]); scan(b[i]);
        max1 = max(max1, b[i]);
    }
    int sieve[max1+1];
    int psa[max1+1][634];
    ms(psa, 0);
    ms(sieve, 0);
    for(int i = 1; i <= max1; ++i){
        for(int j = 1; j*i<=max1; ++j){
            ++sieve[i*j];
        }
        ++psa[i][sieve[i]];
    }
    for(int i = 1; i <= 634; ++i){
        for(int j = 1; j <= max1; ++j){
            psa[j][i]+=psa[j-1][i];
        }
    }
    for(int i = 0; i < T; ++i){
        int temp1 = k[i], temp2 = a[i], temp3 = b[i];
        if(temp1 > 634) cout<<"0"<<endl;
        else cout<<psa[temp3][temp1]-psa[temp2-1][temp1]<<endl;
    }


    return 0;
}
