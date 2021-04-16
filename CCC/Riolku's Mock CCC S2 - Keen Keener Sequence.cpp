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
const ll MM = 7010;
using namespace std;
ll N, a[MM], res; unordered_map<ll, ll> ump1, ump2;
int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; ll tmp = ump1[a[i]];
        // find number of multiples to a number
        for(int j = 0; j < i; ++j){
            if(a[j]!=a[i]) res+=ump2[a[i]*a[j]]-tmp;
            else res+=ump2[a[i]*a[j]]-tmp+1;
        }
        for(int j = 0; j < i; ++j) ++ump2[a[i]*a[j]];
        ++ump1[a[i]];
    }
    cout<<res*8<<endl;
    return 0;
}
