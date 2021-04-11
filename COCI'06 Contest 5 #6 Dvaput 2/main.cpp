#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MAXL 200005
string s; ll p[MAXL],p2[MAXL],h[MAXL],h2[MAXL],b=569,b2=1217,m=1e9+31,m2=2e9+19;
int n;
bool check(int len){
    vector<pair<ll,ll>>vv;
    for(int i = 0; i <= n-len; i++){
        ll v = (((h[i+len] + m - h[i])%m) * p[n-i-1])%m;;
        ll v2 = (((h2[i+len] + m2 - h2[i])%m2) * p2[n-i-1])%m2;
        vv.push_back({v,v2});
    }
    sort(vv.begin(),vv.end());
    for(int i = 1; i < vv.size(); i++){
        if(vv[i].first==vv[i-1].first && vv[i].second==vv[i-1].second) return 1;
    }
    return 0;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    p[0]=p2[0]=1;
    for(int i = 1; i <= n; i++){
        p[i] = (p[i-1]*b)%m;
        p2[i] = (p2[i-1]*b2)%m2;
        h[i] = (h[i-1] + (s[i-1]-'a'+1)*p[i-1])%m;
        h2[i] = (h2[i-1] + (s[i-1]-'a'+1)*p2[i-1])%m2;
    }
    int ans = 0;
    int l = 1, r = n;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        } else r = mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}
