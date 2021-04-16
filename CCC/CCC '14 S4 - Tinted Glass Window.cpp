#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<long long, long long>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MN = 1e3+10;
using namespace std;
struct itm{
    ll lft, top, bot, val;
};
bool cmp(itm a, itm b){
    return a.lft < b.lft;
}
ll N, T, K, lx, rx, ly, ry, tf, res; vector<pii> v; vector<itm> in;
ll run(){
    ll cur = 0, ret = 0;
    for(int i = 0; i < v.size(); ++i){
        cur+=v[i].s;
        while(i < v.size()-1 && v[i+1].f==v[i].f){
            ++i; cur+=v[i].s;
        }
        if(cur>=T && i < v.size()-1) ret+=v[i+1].f-v[i].f;
    }
    return ret;
}
int main()
{
    cin>>N>>T;
    for(int i = 0; i < N; ++i){
        // top left, then bot right
        cin>>lx>>ly>>rx>>ry>>tf;
        in.pb({lx, ry, ly, tf}); in.pb({rx, ry, ly, -tf});
    }
    sort(in.begin(), in.end(), cmp);
    for(int i = 0; i < in.size(); ++i){
        int add = 0;
        v.pb({in[i].bot, in[i].val}); v.pb({in[i].top, -in[i].val});
        while(i<in.size()-1 && in[i+1].lft == in[i].lft){
            ++i; v.pb({in[i].bot, in[i].val}); v.pb({in[i].top, -in[i].val});
        }
        sort(v.begin(), v.end());
        add=run();
        res+=add*(in[i+1].lft-in[i].lft);
    }
    cout<<res<<endl;
    return 0;
}
