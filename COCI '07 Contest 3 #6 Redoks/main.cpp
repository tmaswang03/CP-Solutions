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
const ll MM = 250000+10;
using namespace std;
int N, M, a[MM], t[4*MM], cnt[4*MM][10], lz[4*MM], l, r; char c;
// idea : seg tree + count the number of 9s within a range.
// t array keeps track of the number of each number within the array, shift it up for lazy
// update r-l+1 by 1, subtract 10* the number of counts of 9
// shft the whole thing
void pushup(int v, int l, int r){
    t[v] = 0;
    for(int i = 0; i <= 9; ++i){
        cnt[v][i]=cnt[l][i]+cnt[r][i];
        t[v]+=i*cnt[v][i];
    }
}
void shft(int v){
    int tmp = cnt[v][9]; t[v] = 0;
    for(int i = 9; i >= 1; --i) cnt[v][i] = cnt[v][i-1];
    cnt[v][0] = tmp;
    for(int i = 9; i >= 0; --i) t[v]+=cnt[v][i]*i;
}
void build(int v, int l, int r){
    if(l==r){
        cnt[v][a[l]] = 1; t[v] = a[l];
        return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid);
    build(v<<1|1, mid+1, r);
    pushup(v, v<<1, v<<1|1);
}
void pushdown(int v){
    lz[v]%=10;
    for(int i = 0; i < lz[v]; ++i) shft(v);
    lz[v<<1|1] += lz[v]; lz[v<<1] += lz[v];
    lz[v<<1|1]%=10; lz[v<<1]%=10; lz[v] = 0;
}
void upd(int v, int l, int r, int lo, int hi){
    pushdown(v);
    if(l>hi||r<lo) return;
    if(lo<=l && r <= hi){
        ++lz[v]; lz[v]%=10; pushdown(v);
        return;
    }
    int mid = l+r>>1;
    upd(v<<1, l, mid, lo, min(mid, hi));
    upd(v<<1|1, mid+1, r, max(lo, mid+1), hi);
    pushup(v, v<<1, v<<1|1);
}
int query(int v, int l, int r, int lo, int hi){
    pushdown(v);
    if(l>hi||r<lo) return 0;
    if(lo<=l && r<=hi) return t[v];
    int mid = l+r>>1;
    return query(v<<1, l, mid, lo, min(mid, hi)) + query(v<<1|1, mid+1, r, max(lo, mid+1), hi);
}
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i){
        cin>>c; a[i] = c-'0';
    }
    build(1, 1, N);
    for(int i = 0; i < M; ++i){
        cin>>l>>r;
        cout<<query(1, 1, N, l, r)<<endl;
        upd(1, 1, N, l, r);
    }
    return 0;
}
