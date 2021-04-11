#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10;
using namespace std;
int N, Q;
// credit to https://cp-algorithms.com/
int seg1[4*MM], seg2[4*MM], lazy1[4*MM], lazy2[4*MM];
void push(int cur, int seg[], int lazy[]){
    seg[cur*2] += lazy[cur];
    lazy[cur*2] += lazy[cur];
    seg[cur*2+1] += lazy[cur];
    lazy[cur*2+1] += lazy[cur];
    lazy[cur] = 0;
}

void upd(int cur, int lo, int hi , int l, int r, int val, int seg[], int lazy[]) {
    if (l > r)  return;
    if(l== lo && r == hi){
        seg[cur]+=val;
        lazy[cur]+= val;
        return;
    }
    push(cur, seg, lazy);
    int mid = (lo + hi) / 2;
    upd(cur*2, lo, mid, l, min(r,mid), val, seg, lazy);
    upd(cur*2+1, mid+1, hi, max(l, mid+1), r, val, seg, lazy);
    seg[cur] = seg[cur*2] + seg[cur*2+1];
}

int sum(int cur, int lo, int hi, int l, int r,int seg[], int lazy[]) {
    if (l > r) return 0;
    if (l == lo && r == hi) return seg[cur];
    push(cur, seg, lazy);
    int mid = (lo + hi) / 2;
    return sum(cur*2, lo, mid, l, min(r, mid), seg, lazy) + sum(cur*2+1, mid+1, hi, max(l, mid+1), r, seg, lazy);
}

int main()
{
    scan(N); scan(Q);
    for(int i = 0; i < Q; ++i){
        int com; scan(com);
        if(com^2){
            int l,r,a; scan(l); scan(r); scan(a);
            upd(1,0,N,l, r, a, seg1, lazy1);
            upd(1,0,N,l, r, a-a*l, seg2, lazy2);
        }
        else{
            int l, r; scan(l); scan(r);
            cout<<sum(1,0,N,l, r, seg1, lazy1)+sum(1,0,N,l,r,seg2, lazy2)<<endl;
        }
    }
        for(int i = 0; i <= N; ++i){
            cout<<seg1[i]<<" "<<seg2[i]<<endl;
        }
    return 0;
}
