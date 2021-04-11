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
const ll MM = 3e3+10, MN = 1e5+10;
using namespace std;
int a[MM], N, freq[MN], res;
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){ cin>>a[i]; ++freq[a[i]];}
    sort(a, a+N);
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            if(a[i]==a[j] && freq[a[i]]>=3){
                res = max(res, 3*a[i]);
            }
            else if(a[i]%2==a[j]%2 && freq[(a[i]+a[j])/2]){
                res = max(res, 3*(a[i]+a[j])/2);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
