#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3e6+1;
using namespace std;
char _;
ll arr[MAXN];

int main()
{
    ll N, K, L = 0, R = 0, res = 0; scan(N); scan(K);
    for(int i = 0; i < N; ++i) scan(arr[i]);
    deque<pair<ll, ll> >max1, min1;
    max1.pb({arr[0], 0});
    min1.pb({arr[0], 0});
    while(R < N){
        if(max1.front().f - min1.front().f <= K){
            res += R-L+1; ++R;
            while(!max1.empty() && max1.back().f < arr[R]) max1.pop_back();
            while(!min1.empty() && min1.back().f > arr[R]) min1.pop_back();
            max1.pb({arr[R], R}); min1.pb({arr[R], R});
        }
        else{
           ++L;
           while(!max1.empty() && max1.front().s < L) max1.pop_front();
           while(!min1.empty() && min1.front().s < L) min1.pop_front();
        }
    }
    cout<<res<<endl;
    return 0;
}
