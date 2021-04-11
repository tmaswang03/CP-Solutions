#include<bits/stdc++.h>
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
int a[MM], a1[MM], N;
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]); a1[i] = a[i];
    }
    sort(a, a+N, greater<int>());
    sort(a1, a1+N);
    for(int i = 0; i < N; ++i){
        cout<<a[i]<<" ";
    }cout<<endl;
    for(int i = 0; i < N; ++i){
        cout<<a1[i]<<" ";
    }cout<<endl;
    int lo = 0, hi = N-1, mid, res;
    while(hi > lo){
        mid = (hi+lo)/2;
        if(a[mid]>a1[mid]){
            lo = mid+1;
            res = mid;
        }
        else{
            hi = mid-1;
        }
    }
    printf("%d\n", res);
    return 0;
}
