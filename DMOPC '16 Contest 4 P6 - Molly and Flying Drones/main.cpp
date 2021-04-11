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
using namespace std;
char _;
const ll MAXN = 1e6+20;
ll arr[MAXN], que[MAXN];
int main()
{
    ll N, Q, maxh = 0; scan(N); scan(Q);
    for(int i = 0; i < N; ++i){
        scan(arr[i]);
        maxh = max(maxh, arr[i]);
    }
    stack<ll>s;
    for(int i = 0; i < N; ++i){
        while(!s.empty() && arr[s.top()]> arr[i]){
            ll temp1 = s.top(); s.pop();
            ll left1, right1 = i;
            if(s.empty()) left1 = -1;
            else left1 = s.top();
            que[arr[temp1]] += (temp1-left1) * (right1 - temp1);
        }
        s.push(i);
    }
    while(!s.empty()){
        ll temp1 = s.top(); s.pop();
        ll left1, right1 = N;
        if(s.empty()) left1 = -1;
        else left1 = s.top();
        que[arr[temp1]] += (temp1-left1) * (right1 - temp1);
    }
    for(int i = 1; i <= 1e6+1; ++i){
        que[i] += que[i-1];
    }
    for(int i = 0; i < Q; ++i){
        ll x, y; scan(x); scan(y);
        cout<<que[y]-que[x-1]<<endl;
    }
    return 0;
}
