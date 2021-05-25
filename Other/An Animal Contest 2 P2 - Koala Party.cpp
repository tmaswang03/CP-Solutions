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
const ll MM = 5e3+10;
using namespace std;
ll N, a[MM], res = 1; set <ll> st;
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; st.insert(a[i]);
    }
    sort(a, a+N);
    for(int i = 0; i < N; ++i){
        for(int j = i-1; j >= 0; --j){
            if(i < N-1) res = max(res, 2LL);
            else if(j!=i-1 && a[i-1] >= a[i]-a[j]) res = max(res, 2LL);
            if(st.count(2*a[i]-a[j])) res = 3;
            if((a[i]+a[j])%2==0) res = max(res, 2LL);
        }
    }
    cout<<res<<endl;
    return 0;
}