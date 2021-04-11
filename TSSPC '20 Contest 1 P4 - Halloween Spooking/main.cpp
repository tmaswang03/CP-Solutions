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
const ll MM = 1e6+10;
using namespace std;
int N, M, sum, res, cur, l,  r; deque<int> dq;
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        cin>>cur;
        while(sum + cur > M){
            if(dq.size()> r-l+1){
                r = i-1; l = r-dq.size()+1;
            }
            sum-=dq.front(); dq.pop_front();
        }
        dq.push_back(cur); sum+=cur;
        if(dq.size() > r - l + 1){
            r = i; l = r - dq.size()+1;
        }
    }
    cout<<l+1<<" "<<r+1<<endl;
    return 0;
}
