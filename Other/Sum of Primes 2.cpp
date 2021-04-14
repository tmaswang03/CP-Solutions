#include<bits/stdc++.h>
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
const ll MM = 1e5+10;
using namespace std;
ll psa[MM], primes[MM], N;
int main()
{
    scan(N);
    iota(primes, primes+MM, 0);
	int i = 2;
    while ((i*i) <= 100000)
    {
        if (primes[i] != 0)
        {
            for(int j=2; j<100000; j++)
            {
                if (primes[i]*j > 100000)
                    break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }
    primes[1] = 0;
    for(int i = 1; i <= MM; ++i){
        psa[i] = psa[i-1]+primes[i];
    }
    while(N--){
        int a,b; scan(a); scan(b);
        cout<<psa[b]-psa[a-1]<<endl;
    }
    return 0;
}
