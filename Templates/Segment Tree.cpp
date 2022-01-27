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
const ll MM = 2e5+10;
using namespace std;
int t[4*MM], a[MM], N, Q, l , r, opt;
// maximum in range segment tree
void build (int v, int l, int r) {
    if(l > r) return;
    if(l == r){ t[v] = a[l]; return; }
    int mid = l + r >> 1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    t[v] = max(t[v<<1], t[v<<1|1]);
    return;
}

void upd(int v, int l, int r, int idx, int val) {
    if(l > r) return;
    if(l == r && l == idx) {
        t[v] = val; return;
    }
    int mid = l + r >> 1;
    if(idx <= mid) upd(v<<1, l, mid, idx, val);
    else upd(v<<1|1, mid+1, r, idx, val);
    t[v] = max(t[v<<1], t[v<<1|1]);
}

ll query(int v, int l, int r, int lo, int hi) {
    if(r < lo || l > hi || lo > hi) return 0;
    if(l >= lo && r <= hi) return t[v];
    int mid = l + r >> 1;
    return max(query(v<<1, l, mid, lo, min(mid, hi)), query(v<<1|1, mid+1, r, max(lo, mid+1), hi));
}
int main()
{
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    build(1, 1, N);
    while(Q--) {
        cin>>opt>>l>>r;
        if(opt == 1) {
            // update
            upd(1, 1, N, l, r);
        }
        else{
            cout<<query(1, 1, N, l, r)<<endl;
        }
    }
    return 0;
}
