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
int t[4*MM], N, Q, a[MM], x, k, opt, l, r, ans = 0;
void build(int v, int l, int r){
    if(l==r){
        t[v] = a[l]; return;
    }
    int mid = l+r>>1;
    build(v<<1, l, mid); build(v<<1|1, mid+1, r);
    t[v] = min(t[v<<1], t[v<<1|1]);
}
void upd(int v, int l, int r, int pos, int val){
    if(l==r && r==pos){
        t[v] = val; return;
    }
    int mid = l+r>>1;
    if(mid>=pos) upd(v<<1, l, mid, pos, val);
    else upd(v<<1|1, mid+1, r, pos, val);
    t[v] = min(t[v<<1], t[v<<1|1]);
}
int query(int v, int l, int r, int lo, int hi, int k){
    if(l>hi||r<lo||t[v]>=k) return 0x3f3f3f3f;
    if(lo<=l && r <= hi){
        if(l==r && t[v]<k) return l;
        else{
            int mid = l+r>>1;
            if(t[v<<1]<k) return query(v<<1, l, mid, lo, min(mid, hi), k);
            else return query(v<<1|1, mid+1, r, max(lo, mid+1), hi, k);
        }
    }
    int mid = l+r>>1, lt = query(v<<1, l, mid, lo, min(mid, hi), k);
    if(lt==0x3f3f3f3f) return query(v<<1|1, mid+1, r, max(lo, mid+1), hi, k);
    return lt;
}

int main()
{
    scana(N, Q);
    for(int i = 1; i <= N; ++i) scan(a[i]);
    build(1, 1, N);
    while(Q--){
        scan(opt);
        if(opt==1){
            scana(l, x); l^=ans; x^=ans;
            upd(1, 1, N, l, x);
        }
        else{
            scana(l, r, k); l^=ans; r^=ans; k^=ans;
            int res = query(1, 1, N, l, r, k);
            printf("%d\n", res);
            ans = res;
        }
    }
    return 0;
}
