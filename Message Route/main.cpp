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
const ll MM = 2510;
using namespace std;
ll N, x[MM], y[MM], psa[MM][MM], res = 0; vector<pii> xx, yy;
ll query(int a, int b, int c, int d){
    return psa[c][d] - psa[a-1][d] - psa[c][b-1] + psa[a-1][b-1];
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>x[i]>>y[i]; xx.pb({x[i], i}); yy.pb({y[i], i});
    }
    sort(xx.begin(), xx.end()); sort(yy.begin(), yy.end());
    for(int i = 0; i < xx.size(); ++i){
        x[xx[i].s] = i+1; x[yy[i].s] = i+1;
    }
    for(int i = 0; i < N; ++i) ++psa[x[i]][y[i]];
    for(int i = 0; i < MM; ++i){
        for(int j = 0; j < MM; ++j){
            psa[i][j] += psa[i][j-1]+psa[i-1][j]-psa[i-1][j-1];
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= i; ++j){
            int a = min(x[i], x[j]), b = min(y[i], y[j]), c = max(x[i], x[j]), d = max(y[i], y[j]);
            res+=query(0, b, a, d)*query(c, b, MM-1, d);
        }
    }
    cout<<res+1<<endl;
    return 0;
}
