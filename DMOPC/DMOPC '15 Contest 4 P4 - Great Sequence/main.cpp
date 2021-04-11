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
ll psa[MAXN];
ll gett(int l, int r){
    return psa[r]-psa[l-1];
}
int main()
{
    ll N,K,Q; pair<int, int>arr[MAXN];
    scanf("%d %d %d", &N, &K, &Q);
    for(int i = 1; i <= N; ++i){
        ll temp; scanf("%d", &temp);
        psa[i]+=temp+psa[i-1];
        arr[i] = mp(temp,i);
    }
    sort(arr, arr+N);
    for(int i = 0; i < Q; ++i){
        int a,b,x,y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        bool isless = 0, isbetween1 = 0, isbetween2 = 0;
        if(gett(x,y)<=K) isless = 1;
        ll p1 = lower_bound(arr, arr+N, mp(a,x)) - arr;
        if(arr[p1].second<=y && arr[p1].first == a) isbetween1 = 1;
        ll p2 = lower_bound(arr, arr+N, mp(b,x)) - arr;
        if(arr[p2].second<=y && arr[p2].first == b) isbetween2 = 1;

        if(!isless && isbetween1 && isbetween2){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
