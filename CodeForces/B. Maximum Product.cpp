#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
const ll MM = 5e5+10;
using namespace std;
ll a[MM], N, T, res, tmp, cur;
bool comp(ll a, ll b){return abs(a)>abs(b);}
int main()
{
    cin>>T;
    while(T--){
        cin>>N; res = -1000000; bool neg = 0;
        for(int i = 0; i < N; ++i){ cin>>a[i]; neg |= a[i]>0;}
        sort(a, a+N, comp);
        if(!neg){cout<<a[N-1]*a[N-2]*a[N-3]*a[N-4]*a[N-5]<<endl; continue;}
        tmp = a[0]*a[1]*a[2]*a[3]*a[4]; res = tmp;
        // cases for first 5 :
        // all pos = good
        // all neg, take first 4 and find one positive
        // 4 neg 1 pos = good
        // 4 pos 1 neg = take the negative find positive or take positive find negative
        // 3 pos 2 neg = good
        // 3 neg 2 pos = take pos find neg or take neg find pos
        // 2 pos 3 neg = take neg find pos
        // idea take first 5, then choose 1 and find optimal value using permutation of the first four;
        for(int i = 0; i < 5; ++i){
            cur = tmp;
            if(a[i]!=0)cur = tmp/a[i];
            for(int j = 5; j < N; ++j){
                res = max(res, cur*a[j]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
