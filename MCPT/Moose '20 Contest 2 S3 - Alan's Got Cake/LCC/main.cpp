#include <bits/stdc++.h>
#define ms(a, b) memset(a, b, sizeof(a));
using namespace std;
typedef long long ll;
// N dents, K cuts
// choose K - 1 subsequences to maximze the smallest subseqence

// time complexity log2(max(a_i)) * n^2
// log2(max(a_i)) = log2(1e14) ~ 15
// n^2 = 1000^2 = 10^6
const int MM = 1e+5;
int n, k, jmp[MM]; ll psa[MM], a[MM], val[MM], head[MM];
bool check(ll need) {

    // preprocess
    queue<int>q; int sum = 0; ms(head, 0); ms(jmp, 0x3f3f);
    for(int i = 1; i <= 2*n; ++i){
        q.push(i); sum+=a[i];
        while(sum>=need){
            jmp[q.front()]=q.size(); sum-=a[q.front()]; q.pop();
        }
    }
    while(!q.empty()){
        q.pop();
    }
    for(int i = 1; i <= n; ++i){
        if(head[i]) continue;
        int x = i; head[i] = i;
        for(; x <= 2*n; x = x+jmp[x]){
            head[x] = i;
            if(x+jmp[x] <= 2*n) val[x+jmp[x]] = 1+val[x];
            if(x>n && head[x-n+1]==i && val[x]-val[x-n+1]>=k) return 1;
        }
    }
    //cout << "need: " << need << " cnt: " << cnt << endl;
    return 0;
}
int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> psa[i]; a[i] = a[i+n] = psa[i];
        psa[i+n] = psa[i];
    }
    for(int i=1; i<=2*n; i++) psa[i] += psa[i-1];
    ll lo = 0, hi = 1e14, ans = 0;
    //check(8);
    while(lo <= hi) {
        ll mid = lo + hi >> 1;
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << ans << endl;
}
