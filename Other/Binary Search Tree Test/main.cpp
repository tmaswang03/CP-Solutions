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
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct node{
    ll v, rk, l, r, sz;
    node* c[2]; // left = c[0], right = c[1]
    node (int x){v = x; rk = rand(); sz = 1; c[0]=c[1]=0;}
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
    int getrnk(node* rt, int rank1){ //returns vth smallest number
        if(getsz(rt->c[0])+1==rank1) return rt->v;
        if(getsz(rt->c[0])<rank1) return getrnk(rt->c[1], rank1-getsz(rt->c[0])-1);
        else return getrnk(rt->c[0], rank1);
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
    void del(node*& rt,int x){
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
treap t; node* rt; int N,M, pre = 0, v, x; char opt;
int main()
{
    boost();
    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        cin>>x;
        t.ins(rt, new node(x));
    }
    for(int i = 0; i < M; ++i){
        cin>>opt>>v;
        v^=pre;
        if(opt=='I'){
            t.ins(rt, new node(v));
        }
        else if(opt == 'R'){
            t.del(rt, v);
        }
        else if(opt == 'S'){
            pre = t.getrnk(rt, v);
            cout<<pre<<"\n";
        }
        else{
            pre = t.getlow(rt, v, 0);
            cout<<pre<<"\n";
        }
    }
    t.print(rt);
    return 0;
}
