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
const ll MM = 1e5+10;
using namespace std;
ll N, p, M, a[MM], t[4*MM], lza[4*MM], lzm[4*MM], l, r, opt, x, lft[4*MM], rt[4*MM];
void pushup(int v){
    t[v]=t[v<<1]+t[v<<1|1];
}
void pushdown(int v){
    t[v]%=p; lza[v]%=p; lzm[v]%=p;
    lza[v<<1]=lza[v<<1]*lzm[v]+lza[v];
    lzm[v<<1]*=lzm[v]; lzm[v<<1]%=p, lza[v<<1]%=p;
    lza[v<<1|1]=lza[v<<1|1]*lzm[v]+lza[v];
    lzm[v<<1|1]*=lzm[v]; lzm[v<<1|1]%=p, lza[v<<1|1]%=p;
    t[v<<1]*=lzm[v<<1]; t[v<<1]+=(rt[v<<1]-lft[v<<1]+1)*lza[v<<1];
    t[v<<1]%=p;
    t[v<<1|1]*=lzm[v<<1|1]; t[v<<1|1]+=(rt[v<<1|1]-lft[v<<1|1]+1)*lza[v<<1|1];
    t[v<<1|1]%=p;
    lzm[v] = 1; lza[v] = 0;
}
void build(int v, int l, int r){
    lft[v] = l; rt[v] = r; lzm[v] = 1;
    if(l==r){
        t[v] = a[l]; return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    pushup(v);
}
ll query(int v, int l, int r, int lo, int hi){
    pushdown(v);
    if(l>hi || r<lo) return 0;
    if(l>=lo && r<=hi) return t[v];
    int mid = l+r>>1;
    return query(v<<1, l, mid, lo, min(hi, mid)) + query(v<<1|1, mid+1, r, max(lo, mid+1), hi);
}
void updm(int v, int l, int r, int lo, int hi, int val){
    pushdown(v);
    if(l>hi || r < lo) return;
    if(l>=lo && r<=hi){
        lzm[v]*=val;
        lza[v]*=val;
        t[v]*=val;
        return;
    }
    int mid = l+r>>1;
    updm(v<<1, l, mid, lo, min(mid, hi), val);
    updm(v<<1|1, mid+1, r, max(lo, mid+1), hi, val);
    pushup(v);
}

void upda(int v, int l, int r, int lo, int hi, int val){
    pushdown(v);
    if(l>hi || r < lo) return;
    if(l>=lo && r<=hi){
        lza[v]+=val;
        t[v]+=val*(rt[v]-lft[v]+1);
        return;
    }
    int mid = l+r>>1;
    upda(v<<1, l, mid, lo, min(mid, hi), val);
    upda(v<<1|1, mid+1, r, max(lo, mid+1), hi, val);
    pushup(v);
}


int main()
{
    boost();
    cin>>N>>p;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    build(1, 1, N);
    cout<<query(1, 1, N, 2, 4)<<endl;
    updm(1, 1, N, 2, 4, 2);
    cout<<query(1, 2, N, 2, 4)<<endl;
    cin>>M;
    while(M--){
        cin>>opt>>l>>r; ll res = 0;
        if(opt!=3) cin>>x;
        if(opt==1){
            updm(1, 1, N, l, r, x);
        }
        else if(opt==2){
            upda(1, 1, N, l, r, x);
        }
        else{
            cout<<query(1, 1, N, l, r)<<endl;
        }
    }
    return 0;
}
