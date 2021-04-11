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
const ll MM = 1e5+3;
using namespace std;
ll N, D, K, P, a[MM]; priority_queue<ll> pq; double X;
int main()
{
    cin>>N>>D>>K>>X; X = (100-X)/100;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; pq.push(a[i]);
    }
    cin>>P;
    while(K > 0 && pq.top() >= P){
        ll cur = pq.top(); pq.pop();
        pq.push(cur*X);
        --K;
    }
    if(pq.top()<P) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
