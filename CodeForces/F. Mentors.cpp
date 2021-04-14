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
const ll MM = 2e5+10;
using namespace std;
int N, K, r[MM], a[MM], cnt[MM], x, y;
int main()
{
    cin>>N>>K;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; r[i] = a[i];
    }
    sort(a, a+N);
    for(int i = 0; i < N; ++i){
        cnt[i] = lower_bound(a, a+N, r[i])-a;
    }
    for(int i = 0; i < K; ++i){
        cin>>x>>y; --x; --y;
        if(r[x]>r[y]) --cnt[x];
        else if(r[y]>r[x]) --cnt[y];
    }
    for(int i = 0; i < N; ++i){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
