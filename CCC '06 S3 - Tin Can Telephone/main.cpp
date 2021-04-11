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
const ll MM = 40;
using namespace std;
int N, M, xr, xj, yr, yj, cnt; pii a[MM]; double m, b;
//
bool inrng(int lt, int rt, int x){
    int l = min(lt, rt), r = max(lt, rt);
    return l<=x&&r>=x;
}
bool check(int i, int j){
    double tm = 1.0*(a[i].s-a[j].s)/(1.0*(a[i].f-a[j].f)), tb = a[i].s - tm*a[i].f;
    if(xr==xj && a[i].f!=a[j].f){ return inrng(yr, yj, xr*tm+tb) && inrng(a[i].f, a[j].f, xr); }
    if(xr==xj && a[i].f==a[j].f && a[i].f==xr){
        return(inrng(yr, yj, a[i].s)||inrng(yr, yj, a[j].s)||(max(yr, yj)<=max(a[i].s, a[j].s)&& min(yr, yj) >= min(a[i].s, a[j].s)));
    }
    if(isnan((tb-b)/(m-tm))) return (min(xr, xj)<=a[i].f && max(xr, xj)>=a[i].f && tb==b);
    double res = (tb-b)/(m-tm);
    if(res<min(a[i].f, a[j].f) || res>max(a[i].f, a[j].f) || res < min(xr, xj) || res > max(xr, xj)) return 0;
    return 1;
}
bool run(){
    for(int i = 0; i < M-1; ++i){
        if(check(i, i+1)) return 1;
    }
    if(check(M-1, 0)) return 1;
    return 0;
}
int main()
{
    cin>>xr>>yr>>xj>>yj;
    m = 1.0*(yj-yr)/(1.0*(xj-xr)); b = yr - xr*m;
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>M;
        for(int j = 0; j < M; ++j) cin>>a[j].f>>a[j].s;
        sort(a, a+M);
        cnt+=run();
    }
    cout<<cnt<<endl;
    return 0;
}
