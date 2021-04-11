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
ll const MAXN = 1e5+1;
using namespace std;
ll psa[MAXN+1], diff[MAXN+1], arr[MAXN+1];
vector <int> v; vector<pair<int, int> >v2, q;
ll getsum(int l, int r){
    return psa[r]-psa[l-1];
}

int main()
{
    int N; int Q; scan(N); scan(Q);
    for(int i = 0; i < N; ++i){
        int a; scan(a);
        v.pb(a);
    }
    for(int i = 0; i < Q; ++i){
        int l,r ; scan(l); scan(r);
        diff[l-1]+=1; diff[r]-=1;
        q.pb({l,r});
    }
    for(int i = 0; i < N; ++i){
        diff[i]+=diff[i-1];
    }
    for(int i = 0; i < N; ++i){
        v2.pb({diff[i],i});
    }
    sort(v.begin(),v.end());
    sort(v2.begin(), v2.end()); //amount, inde
    for(int i = 0; i < N; ++i){
        arr[v2[i].second]=v.back();
        v.pop_back();
    }
    for(int i = 1; i <= N; ++i){
        psa[i]=arr[i-1]+psa[i-1];
    }
    ll total = 0;
    for(int i = 0; i < Q; ++i){
        total += getsum(q[i].first,q[i].second);
    }
    cout<<total<<endl;


    return 0;
}
