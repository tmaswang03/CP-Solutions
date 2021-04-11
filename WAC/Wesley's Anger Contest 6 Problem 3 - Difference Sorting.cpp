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
const ll MM = 2e5+10;
using namespace std;
ll a[MM], N, ma, res, fin[MM]; pii tmp[MM];
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; tmp[i] = {a[i], i};
    }
    sort(tmp, tmp+N);
    for(int i = 0; i < N; ++i){
        fin[tmp[i].s] = i;
    }
    for(int i = 0; i < N; ++i){
        int pt1 = lower_bound(tmp, tmp+N, mp(a[i], i) ) - tmp;
        int pt2 = lower_bound(tmp, tmp+N, mp(a[pt1], i) ) - tmp;
        if(pt1 > pt2) swap(pt1, pt2);
        for(int i = pt1+1; i <= pt2; ++i){
            res = max(res, tmp[i].f - tmp[i-1].f);
            swap(tmp[i].s, tmp[i-1].s); swap(a[tmp[i].s], a[tmp[i-1].s]);
        }
    }
    cout<<res<<endl;

    return 0;
}
