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
const ll MM = 5e4+10;
using namespace std;
ll S, N, Q, num;
struct bb{
    ll b, d, c, idx; // speed, venom, claw
    bool operator < (const bb &o){
        if(o.b==b && o.d == d && o.c == c) return (idx < o.idx);
        if(b > o.b) return 1;
        else if(b < o.b) return 0;
        if(b<S) return (d > o.d);
        return c > o.c;
    }
} a[MM];
int main()
{
    cin>>S>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i].b>>a[i].d>>a[i].c; a[i].idx = i;
    }
    cin>>Q; sort(a, a+N);
    while(Q--){
        cin>>num;
        cout<<a[num-1].idx+1<<endl;
    }
    return 0;
}
