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
const ll MM = 5e5+10;
using namespace std;
ll N, Q, a[MM], res[MM], opt, lft, rt, x, bit[MM], bit1[MM], st = 0;
struct E{
    int l, idx, val, op;
    bool operator <(const E &o){
        if(l==o.l) return op < o.op;
        return l < o.l;
    }
};
vector<E> v;
void upd(int x, int val){
    for(; x < MM; x+=x&-x) bit[x]+=val;
}
ll query(int x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res+=bit[x];
    return res;
}
void upd1(int x, int val){
    for(; x < MM; x+=x&-x) bit1[x]+=val;
}
ll query1(int x){
    ll res = 0;
    for(; x > 0; x-=x&-x) res+=bit1[x];
    return res;
}
int main()
{
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= Q; ++i){
        cin>>opt>>lft>>rt;
        if(opt==1){
            cin>>x;
            v.pb({lft, i, x, 0}); v.pb({rt+1, i, -x, 0});
        }
        else{
            v.pb({lft, i, 0, 1}); v.pb({rt+1, i, 1, 1});
            // 0 = lft, 1 = rt;
        }
    }
    // l, idx, val, op
    sort(v.begin(), v.end());
    // use one bit to keep track of the values for all indeces <= i at a cur point
    // use another bit to keep track of the values that you are querying for when you pass an index
    // this bit can then be used to add to the total revenue
    ll cur = 0, cnt = 0;
    for(int i = 1; i <= N; ++i ){
        while(v[st].l<=i && st < v.size()){
            int id = v[st].idx, qu = v[st].op, va = v[st].val;
            if(qu==0){
                upd(id, va);
                cur+=query1(MM-id)*va;
            }
            else if (qu==1){
                if(va == 0){
                    cur+=query(id); ++cnt;
                    upd1(MM-id, 1);
                }
                else{
                    --cnt; cur-=query(id);
                    upd1(MM-id, -1);
                }
            }
            ++st;
        }
        res[i] = cur+a[i]*cnt;
    }
    for(int i = 1; i <= N; ++i) cout<<res[i]<<" ";
    return 0;
}
