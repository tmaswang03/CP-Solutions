#include<bits/stdc++.h>
typedef long long ll;
const ll MM = 1e5+10;
using namespace std;
ll N, a[MM], K, L;
bool solve(ll val){
    ll add = K*L, cnt = 0;
    for(int i = N-1; i >= 0; --i){
        if(val - a[i] > K || val - a[i] > add) return 0;
        if(a[i] < val) add -= val - a[i];
        ++cnt;
        if(cnt>=val) return 1;
    }
    if(cnt>=val) return 1;
    return 0;
}
int main() {
    cin>>N>>K>>L;
    for(int i = 0; i < N; ++i) cin>>a[i];
    sort(a, a+N);
    ll lo = 0, hi = N, mid, res;
    while(hi>lo){
        mid = (lo+hi+1)>>1;
        if(solve(mid)){
            lo = mid; res = mid;
        }
        else hi = mid-1;
    }
    cout<<res<<endl;
}