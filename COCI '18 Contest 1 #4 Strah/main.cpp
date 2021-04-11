#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define boost() cin.tie(0); cin.sync_with_stdio(0);
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MAXN = 2e3+10;
using namespace std;
int dp[MAXN][MAXN], t[MAXN];
bool a[MAXN][MAXN];
ll calc(int n){
    return n*(n+1)/2;
}

int main()
{
    boost();
    int N, M; cin>>N>>M; ms(t, 0);
    ll res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            char s; cin>>s;
            a[i][j] = (s=='.');
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            t[j] = t[j]*a[i][j]+a[i][j];
        }
        stack<int>s;
        for(int j = 0; j <= M; ++j){
            while(!s.empty() && t[s.top()] > t[j]){
                int ind = s.top(); s.pop();
                int l = (s.empty() ? -1 : s.top());
                res+= calc(t[ind])*(calc(ind - l)*(j-ind) + calc(j-ind)*(ind - l) - (ind-l)*(j-ind));
            }
            s.push(j);
        }
    }
    cout<<res<<endl;
    return 0;
}
