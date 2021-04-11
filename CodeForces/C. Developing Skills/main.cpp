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
const ll MM = 1e5+10;
using namespace std;
int a[MM], N, K, pt = 0, t = 0, tot = 0;
queue<int> q;
bool comp(int &a, int &b){
    if(a%10==b%10) return a<b;
    return a%10>b%10;
}
int main()
{
    cin>>N>>K;
    for(int i = 0; i < N; ++i){
        cin>>a[i];
    }
    sort(a, a+N, comp);
    for(int i = 0; i < N; ++i){
        q.push(i);
    }
    while(!q.empty() && K!=0){
        auto pt = q.front(); q.pop();
        if(a[pt]==100) continue;
        t = min(K, 10-a[pt]%10);
        a[pt]+=t; K-=t;
        q.push(pt);
    }
    for(int i = 0; i < N; ++i){
        tot+=a[i]/10;
    }
    cout<<tot<<endl;
    return 0;
}
