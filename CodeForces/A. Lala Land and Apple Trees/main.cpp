#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
vector<pair<int, int> >pos, neg;
int cnt1, cnt2;
int main()
{
    int n, res = 0; cin>>n;
    for(int i = 0; i < n; ++i){
        int x, a; cin>>x>>a;
        if(x<0){ neg.pb({x, a}); ++cnt1;}
        else {pos.pb({x,a}); ++cnt2;}
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<pair<int, int > >());
    if(cnt1 > cnt2){ // more negative than positive
        for(auto && i : pos) res+=i.s;
        for(int i = 0; i <= cnt2; ++i) res+=neg[i].s;
    }
    else if(cnt1 < cnt2){
        for(auto && i : neg) res+=i.s;
        for(int i = 0; i <= cnt1; ++i) res+=pos[i].s;
    }
    else{
        for(auto && i : neg) res+=i.s;
        for(auto && i : pos) res+=i.s;
    }
    cout<<res<<endl;
    return 0;
}
