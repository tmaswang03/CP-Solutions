#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
const ll MAXN = 50, inf = 0x3f3f3f3f;
using namespace std;

int main()
{
    ll t; cin>>t;
    for(int i = 0; i < t; ++i){
        ll N, max1 = -1; cin>>N; ll arr[N+1];
        for(ll j = 0; j < N; ++j){
            cin>>arr[j];
        }
        sort(arr, arr+N);
        for(ll r = 0; r < N; ++r){
            for(ll l = 0; l < r; ++l){
                ll p1 = l, p2 = r, sum = arr[r]+arr[l];
                while(p1 < p2){

                }
            }
        }
        cout<<max1<<endl;
    }
    return 0;
}
