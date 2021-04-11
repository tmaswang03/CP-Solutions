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
const ll MM = 2e5+10;
using namespace std;
int N, M, res = 0, cnt; vector<int> cmprs;
int gett(int cur){
    return lower_bound(cmprs.begin(), cmprs.end(), cur)-cmprs.begin();
}
// the two sorted is always a good arrangement;
struct shoe{
    int sz, col;
    bool operator < (shoe &o){
        return sz > o.sz;
    }
}a[MM], b[MM];
struct itm{
    int sz, need, idx;
    bool operator < (itm &o){
        if(sz==o.sz){
            return need < o.need;
        }
        return sz < o.sz;
    }
};
bool cmp1(itm a, itm b){
    if(a.sz==b.sz) return a.need<b.need;
    return a.sz<b.sz;
}
bool cmp(shoe a, shoe b){
    return a.sz>b.sz;
}
vector<itm> v[MM];
int main()
{
    // if a person is at fav shoe it is always optimal to keep it that way
    // if two people don't have fav, 1 has fav of other, swap the two
    // keep track of available sizes of a shoe colour and the sizes that the assigned shoe needs
    //
    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        cin>>a[i].col>>a[i].sz; cmprs.pb(a[i].col);
    }
    sort(cmprs.begin(), cmprs.end());
    for(int i = 0; i < N; ++i){
        cin>>b[i].col>>b[i].sz;
    }
    sort(a, a+N); sort(b, b+N);
    for(int i = 0; i < N; ++i){
        v[gett(a[i].col)].pb({a[i].sz, b[i].sz});
    }
    for(int i = 0; i < N; ++i){
        int ptr = lower_bound(v[b[i].col].begin(), v[b[i].col].end(),  ({b[i].sz, a[i].sz}, cmp1)) - v[b[i].col].begin();
        if(ptr!=v.end()&&v[b[i].col][ptr].){
            ++cnt; swap(b[i], b[v[b[i].col].idx]);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
