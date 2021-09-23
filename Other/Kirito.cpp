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
const ll MM = 5e3+10, MN = 2e3+10, seed = 131, mod = 1e9+7;
using namespace std;
ll N, M, Q, hsh[MN][MM], t[MN<<2], id[MN], r1, r2; string row;
ll modd(ll in){ return (in%mod + mod)%mod; }

int bsearch (int r, int x, int y) {
    int lo = 0, hi = r, mid,res = 0;
    while(hi > lo) {
        mid = (lo+hi+1)>>1;
        if(hsh[x][mid] == hsh[y][mid]) {
            res = mid; lo = mid;
        }
        else hi = mid-1;
    }
    return res;
}

void build(int l, int r, int v) {
    if(l == r) {
        t[v] = M; return;
    }
    int mid = l+r>>1;
    build(l, mid, v<<1); build(mid+1, r, v<<1|1);
    t[v] = bsearch(min(t[v<<1], t[v<<1|1]), mid, mid+1);
}

ll query(int l, int r, int v, int lo, int hi) {
    if(lo <= l && r <= hi) return t[v];
    if(hi < l || lo > r || lo > hi) return MM;
    int mid = l+r>>1, lft, rt;
    lft = query(l, mid, v<<1, lo, min(hi, mid)); rt = query(mid+1, r, v<<1|1, max(mid+1, lo), hi);
    if(lft == MM) return rt;
    else if(rt == MM) return lft;
//    cout<<bsearch(min(lft, rt), id[l], id[r])<<" "<<l<<" "<<r<<endl;
    return bsearch(min(lft, rt), id[mid], id[mid+1]);
}

void upd (int l, int r, int v, int idx) {
    if(l > idx || r < idx) return;
    if(l==r && l == idx) {
        t[v] = M; return;
    }
    int mid = l+r>>1;
    if(mid >= idx) upd(l, mid, v<<1, idx);
    else upd(mid+1, r, v<<1|1, idx);
    t[v] = bsearch(min(t[v<<1], t[v<<1|1]), id[mid], id[mid+1]);
}
int main()
{
    // idea: hash, rows, map input to columns, binary search
    // time complexity for queries : o(logM) o(Qlogm)
    cin>>N>>M;
    for(int i = 1; i <= N; ++i) id[i] = i;
    for(int i = 1; i <= N; ++i) {
        cin>>row;
        for(int j = 1; j <= row.length(); ++j) {
            hsh[i][j] = modd(hsh[i][j-1]*seed + (row[j-1] - '0' + 1));
        }
    }
    build(1, N, 1);
    cin>>Q;
    while(Q--) {
        cin>>r1>>r2;
        cout<<(r2-r1+1)*query(1, N, 1, r1, r2)<<endl;
        swap(id[r1], id[r2]);
        upd(1, N, 1, r1); upd(1, N, 1, r2);
    }
    return 0;
}