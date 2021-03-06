#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MM = 1e5+10, inf = 1e12+7;
using namespace std;
struct pt{
    int x, y;
};
pt a[MM];
deque<pt>dq;
pair<ll, ll> dp[MM];
bool comp(pt a, pt b){return a.x<b.x || (a.y>b.y && a.x==b.x);}
ll sqr(ll in){ return(in*in);}
//if you are to make a square it must be of minimal area (max(x,y)-min(x,y)+1)^2;
// sort points by increasing x coordinate,
// at each point you have a choice, join it in the previous square or create a separate square
// dp states hold the minimum cost if next split is at this point to hold points from i to n;
// subtask 2 (x==y);
// dp states --> dp[k][n] = min0-n(dp[k-1][i]) + (a[i+1].x-a[n].x+1)^2
// no overlaps
// size of square = (a[cur].y -a[pre].x+1)^2
// bottom right = (a[i].y, a[i].y);
// bottom left = (a[i].y,a[i].x);
// top right = (a[i].x, a[i].y);
// top left = (a[i].x,a[i].x);
// y is always > than x
// overlaps = (a[i].x - a[j].y+1)^2
// with overlaps = dp[k][i] = min0-n(dp[k-1][j]) + (a[j+1].y-a[i].x+1)^2 - (a[i-1].y-a[i].x+1)^2
// get rid of a point if fully incapsulated by another point no matter the picture taken
// this happens when a[i].y >= a[j].y and a[i].x <= a[j].x
// you do not need point a[i];
// time for cht (:
//  dp[k][i] = dp[k][i] = min0-n(dp[k-1][j]) + (a[j+1].y-a[i].x+1)^2 - (a[j].y-a[j+1].x+1)^2
//  dp[k][i] = dp[k][i] = min0-n(dp[k-1][h]) + (a[h+1].y-a[i].x+1)^2 - (a[h].y-a[h+1].x+1)^2
// wqs bin search :DDD
ll gett(int pre, int cur){
    return dp[pre].f+sqr(a[cur].y-a[pre+1].x+1) - sqr(max(0, a[pre].y - a[pre+1].x+1));
}

ld cht(int j, int h){
    return (ld)(dp[j].f-dp[h].f-sqr(max(0,a[j].y-a[j+1].x+1))+sqr(max(0,a[h].y-a[h+1].x+1))-2*(a[j+1].x) + sqr(a[j+1].x)
                +  2*(a[h+1].x)  - sqr(a[h+1].x)) / (ld)(a[j+1].x-a[h+1].x);
}

pair<ll, ll>  getcht(int n, ll c){
    vector<ll>hull; hull.pb(0);
    ll start = 0;
    for(int i = 0; i < n; ++i){
        dp[i].f = sqr(a[i].y-a[0].x+1)+c;
        dp[i].s = 1;
    }
    for(int i = 1; i < n; ++i){
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[start],B = hull[start+1];
            if(cht(A,B) < 2.0*a[i].y) ++start;
            else break;
        }
        if(gett(hull[start],i) + c < dp[i].f){
            dp[i].f=gett(hull[start],i) + c;
            dp[i].s = dp[hull[start]].s + 1;
        }
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[hull.size()-2],B = hull[hull.size()-1];
            if(cht(A,B)>cht(B,i)) hull.pop_back();
            else break;
        }
        hull.push_back(i);
    }
    return dp[n-1];
}

ll alien(ll n, ll k){
    ll lo = 0, hi = 1e12, mid;
    pair<ll, ll>res;
    for(int i = 0; i < 120; ++i){
        mid = (lo+hi)/2;
        res = getcht(n, mid);
        if(res.s < k){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    return res.f - mid*res.s;
}


long long take_photos(int n, int m, int k, int* r, int* c){
    ms(dp, inf);
    for(int i = 0; i < n; ++i){
        if(r[i]>c[i]) swap(r[i], c[i]);
        a[i] = {r[i], c[i]};
    }
    sort(a, a+n, comp);
    for(int i = 0; i < n; ++i){
        if(dq.empty() || dq.back().x>a[i].x || dq.back().y < a[i].y) dq.pb(a[i]);
    }
    n = dq.size();
    for(int i = 0; i < dq.size(); ++i) a[i] = dq[i];
    ll res = alien(n, min(n, k));
    return res;
}


int main()
{

    boost();
    int r[MM], c[MM], n, m, k;
    cin>>n>>m>>k;
    for(int i = 0; i < n; ++i){
        cin>>r[i]>>c[i];
    }
    cout<<take_photos(n,m,k,r,c)<<endl;
    return 0;
}
