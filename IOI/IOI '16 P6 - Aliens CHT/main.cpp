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
const ll MM = 5e3+10, inf = 1e12+7;
using namespace std;
struct pt{
    int x, y;
};
pt a[MM];
deque<pt>dq;
ll dp[MM][MM]; // point you are on, splits you are at;
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
ll gett(int pre, int cur, int splt){
    return dp[splt-1][pre]+sqr(a[cur].y-a[pre+1].x+1) - sqr(max(0, a[pre].y - a[pre+1].x+1));
}

ld cht(int j, int h, int splt){
    return (ld)(dp[splt-1][j]-dp[splt-1][h]-sqr(max(0,a[j].y-a[j+1].x+1))+sqr(max(0,a[h].y-a[h+1].x+1))-2*(a[j+1].x) + sqr(a[j+1].x)
                +  2*(a[h+1].x)  - sqr(a[h+1].x)) / (ld)(a[j+1].x-a[h+1].x);
}

void getcht(int splt, int n){
    vector<ll>hull; hull.pb(0);
    ll start = 0;
    for(int i = 1; i < n; ++i){
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[start],B = hull[start+1];
            if(cht(A,B, splt) < 2.0*a[i].y) ++start;
            else break;
        }
        dp[splt][i]=gett(hull[start],i,splt);
        while(start <= (ll) hull.size() - 2) {
            ll A = hull[hull.size()-2],B = hull[hull.size()-1];
            if(cht(A,B, splt)>cht(B,i, splt)) hull.pop_back();
            else break;
        }
        hull.push_back(i);
    }
}

long long take_photos(int n, int m, int k, int* r, int* c){
    ms(dp, inf);
    for(int i = 0; i < n; ++i){
        if(r[i]>c[i]) swap(r[i], c[i]);
        a[i] = {r[i], c[i]};
    }
    sort(a, a+n, comp);
    for(int i = 0; i < n; ++i){
        if(dq.empty() || dq.back().x>a[i].x || dq.back().y < a[i].y){
            dq.pb(a[i]);
        }
    }
    n = dq.size();
    for(int i = 0; i < dq.size(); ++i){
        a[i] = dq[i];
    }
    for(int i = 0; i < n; ++i){
        dp[1][i] = sqr(a[i].y-a[0].x+1);
    }
    for(int splt = 2; splt <= min(n,k); ++splt){
        getcht(splt, n);
    }

    return dp[min(n,k)][n-1];
}


int main()
{
/*
10 20 3
  3 3
 15 15
 10 10
 18 18
 4 4
 7 7
 15 15
 2 2
 10 10
 7 7

 res = 41;
*/

/*
5 7 2
 0 3
 4 4
 4 5
 4 6
 4 6
 */
    boost();
    int r[MM], c[MM], n, m, k;
    cin>>n>>m>>k;
    for(int i = 0; i < n; ++i){
        cin>>r[i]>>c[i];
    }
    cout<<take_photos(n,m,k,r,c)<<endl;
    return 0;
}
