#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10;
using namespace std;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seed1); uniform_int_distribution<ll> dis(1, 1e10);
struct node{
    ll v, rk, l, r, sz, id;
    node* c[2]; // left = c[0], right = c[1]
    node (int x, int i){v = x; rk = dis(gen); sz = 1; c[0]=c[1]=0; id = i;}
};
struct treap{
    int getsz(node* rt){ return !rt ? 0 : rt->sz;}
    void upd(node* rt){if(rt) rt->sz = getsz(rt->c[0]) + 1 + getsz(rt->c[1]);}
    void rot(node*& rt, int dir){ //dir = 0, left rotation; dir = 1, right rotation
        node* ch = rt->c[!dir];
        rt->c[!dir] = ch->c[dir];
        ch->c[dir] = rt;
        upd(rt); upd(ch);
        rt = ch;
    }
    void ins(node*& rt, node* x){
        if(!rt){ rt = x; x->sz=1;}
        else{
            int dir = (x->v > rt ->v);
            ins(rt->c[dir], x);
            if(rt->c[dir]->rk < rt->rk) rot(rt, !dir);
        }
        upd(rt);
    }
    node* in(node* rt, node* x){
        if(!rt) return nullptr;
        if(rt->v==x->v) return rt;
        if(rt->v > x->v) return in(rt->c[0], x);
        return in(rt->c[1], x);
    }
    int getrnk(node* rt, int k){ //returns vth smallest number
        if(getsz(rt->c[0])+1==k) return rt->id;
        if(getsz(rt->c[0])<k) return getrnk(rt->c[1], k-getsz(rt->c[0])-1);
        else return getrnk(rt->c[0], k);
    }
    int kth (node *rt, int k, int add){
        int pos = add+getsz(rt->c[1]);
        if(pos==k) return rt->id;
        else if(pos < k) return kth(rt->c[0], k, pos+1);
        else return kth(rt->c[1], k, add);
    }
    int getlow(node* rt, int x, int add){ // returns first occurence of value;
        if(!rt) return -1;
        if(rt->v == x){
            int tmp = getlow(rt->c[0], x, add);
            if(tmp!=-1) return tmp;
            return add+getsz(rt->c[0])+1;
        }
        else if(rt->v < x) return getlow(rt->c[1], x, add+getsz(rt->c[0])+1);
        return getlow(rt->c[0], x, add);
    }
    void del(node*& rt, int x){
        if(!rt) return;
        if(rt->v==x){
            if(!rt->c[0]) rt = rt->c[1];
            else if(!rt->c[1]) rt = rt->c[0];
            else{
                int dir = rt->c[0]->rk > rt->c[1]->rk;
                rot(rt, !dir); del(rt->c[!dir], x);
            }
        }
        else del(rt->c[rt->v<x], x);
        upd(rt);
    }
    void pre(node*& rt){
        if(!rt) return;
        cout<<rt->v<<" ";
        pre(rt->c[0]); pre(rt->c[1]);
    }
    void print(node* rt){
        if(!rt) return;
        print(rt->c[0]);
        cout<<rt->v<<" ";
        print(rt->c[1]);
    }

};
treap t; node* rt; int N, a[MM], x,y, cnt = 0; char opt;
int main()
{
    scan(N);
    while(N--){
        scanf("%c", &opt);
        if(opt=='N'){
            scan(x); scan(y);  a[x] = y;
            t.ins(rt, new node(y,x));
        }
        else if(opt=='M'){
            scan(x); scan(y);
            t.del(rt, a[x]); a[x] = y;
            t.ins(rt, new node(a[x], x));
        }
        else{
            scan(x);
            printf("%d\n", t.kth(rt, x-1, 0));
        }
    }
    return 0;
}
