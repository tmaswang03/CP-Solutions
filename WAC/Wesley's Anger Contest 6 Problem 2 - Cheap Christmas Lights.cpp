#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
int N, M, tmp, cnt; bool a[MM];
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i){ cin>>a[i]; cnt+=a[i]; }
    if(cnt==0){ cout<<0<<endl; return 0;}
    // cnt = number of lights to turn off
    for(int i = 1; i <= M; ++i){
        cin>>tmp;
        if(a[tmp]) a[tmp] = 0;
        else a[tmp] = 1;
        if(a[tmp]) ++cnt;
        else --cnt;
        if(cnt<=i){
            cout<<i<<endl; return 0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
