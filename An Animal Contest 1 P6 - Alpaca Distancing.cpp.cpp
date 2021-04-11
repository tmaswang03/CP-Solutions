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
const ll MM = 1e5+10, MN = 3e5+10;
using namespace std;
int N, dp[MM], bit[MN], ans; pii a[MM]; vector<int> v;
int gett(int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin()+1;
}
void upd(int x, int val){
    for(; x < MN; x+=x&-x) bit[x] = max(bit[x], val);
}
int que(int x){
    int res = 0;
    for(; x > 0; x-=x&-x) res = max(res, bit[x]);
    return res;
}
struct itm{
    int ma, idx, val;
};
bool comp(itm a, itm b){
    return a.ma > b.ma;
}
priority_queue<itm, vector<itm>, function<bool(itm, itm)>>pq(comp);
int main()
{
    // idea : dp contain or not
    //
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i].f>>a[i].s;
        v.pb(a[i].f); v.pb(a[i].f-a[i].s); v.pb(a[i].f+a[i].s);
    }
    sort(a, a+N);
    sort(v.begin(), v.end());
    for(int i = 0; i < N; ++i){
        while(!pq.empty()&&pq.top().ma<=a[i].f){
            upd(gett(pq.top().idx), pq.top().val); pq.pop();
        }
        int tmp = que(gett(a[i].f-a[i].s));
        ans = max(ans, tmp+1);
        pq.push({a[i].f+a[i].s,a[i].f, tmp+1});
    }
    cout<<ans<<endl;
    return 0;
}
