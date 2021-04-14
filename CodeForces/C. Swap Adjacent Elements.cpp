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
int N, a[MM], r = 1; bool flp[MM]; char c;
// if an entire portion is together, you can sort it all
bool check(){
    for(int i = 1; i <= N; ++i){
        if(a[i-1]>a[i]) return 0;
    }
    return 1;
}
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i < N; ++i){ cin>>c; flp[i] = c-'0';}
    for(int l = 1; l <= N; ++l){
        r = l;
        while(flp[r]) ++r;
        sort(a+l, a+r+1);
        l = r;
    }
    if(check())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
