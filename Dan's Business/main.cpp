#include<bits/stdc++.h>
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
const ll MM = 1e6+10;
using namespace std;
int N, M, a[MM], v, s, e, t[3*MM], lz[3*MM];
void resolve(int v){
    t[v<<1|1]+=lz[v];
    t[v<<1]+=lz[v];
    lz[(v<<1)|1]+=lz[v];
    lz[v<<1]+=lz[v];
    lz[v] = 0;
}
void build(int v, int l, int r){
    if(l==r){
        t[v] = a[l]; return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    t[v] = min(t[v<<1], t[v<<1|1]);
}
void inc(int lo, int hi, int l, int r, int v, int val){
    if(l > r) return;
    if(lo==l && r==hi){
        t[v]+=val; lz[v]+= val; return;
    }
    resolve(v);
    int mid = (lo+hi)>>1;
    inc(lo, mid, l, min(r, mid), v<<1, val);
    inc(mid+1 , hi, max(l, mid+1), r, (v<<1)|1, val);
    t[v] = min(t[v<<1], t[(v<<1)|1]);
}
int query(int lo, int hi, int l, int r, int v){
    if(l > r) return 0x3f3f3f3f;
    if(l <= lo && hi <= r) return t[v];
    resolve(v);
    int mid = (lo+hi)>>1;
    return min(query(lo, mid, l, min(r, mid), v<<1),  query(mid+1, hi, max(l, mid+1), r , (v<<1)|1));
}
int main()
{
    //
    cin>>N>>M;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    build(1, 1, N);
    for(int i = 1; i <= M; ++i){
        cin>>v>>s>>e;
        inc(1, N, s, e, 1, -v);
        if(query(1, N, s, e, 1)<0){
            cout<<-1<<"\n"<<i<<endl; return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
