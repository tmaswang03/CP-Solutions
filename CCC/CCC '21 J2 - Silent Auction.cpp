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
const ll MM = 1e2+10;
using namespace std;
struct bid {
    int val, idx; string name; 
};
bool cmp(bid x, bid y) {
    if(x.val > y.val) return 1;
    if(y.val > x.val) return 0; 
    return x.idx < y.idx; 
}
bid a[MM]; int N;
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){ cin>>a[i].name>>a[i].val; a[i].idx = i; }
    sort(a, a+N, cmp);
    cout<<a[0].name<<endl;
    return 0;
}