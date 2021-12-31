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
const ll MM = 1e6+10;
using namespace std;
int N; double sum; priority_queue<double> pq; pair<int, double> a[MM];
bool cmp(pair<int, double> x, pair<int, double> y) {
    return x.f < y.f;
}
int main()
{
    for(int t = 0; t < 10; ++t) {
        cin>>N; while(!pq.empty()) pq.pop();
        for(int i = 1; i <= N; ++i) {
            cin>>a[i].f>>a[i].s;
        }
        sort(a+1, a+N+1, cmp); int pt = N; sum = 0;
        for(int i = N; i >= 1; --i) {
            while(a[pt].f >= i && pt > 0) pq.push(a[pt--].s);
            if(!pq.empty()){ sum += pq.top(); pq.pop(); }
        }
        cout<<fixed<<setprecision(4)<<sum<<endl;
    }
    return 0;
}