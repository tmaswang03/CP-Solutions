#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int r[10], a[10], sum[10];
int dfs(int cur){
    int cnt = 0;
    if(cur==6){
        for(int i = 0; i < 4; ++i) cnt += (sum[i]>r[i]);
        return cnt;
    }
    for(int i = 0; i < 4; ++i){
        sum[i]+=a[cur];
        cnt = max(cnt, dfs(cur+1));
        sum[i]-=a[cur];
    }
    return cnt;
}
int main()
{
    for(int i = 0; i < 4; ++i) cin>>r[i];
    for(int i = 0; i < 6; ++i) cin>>a[i];
    cout<<dfs(0)<<endl;
    return 0;
}
