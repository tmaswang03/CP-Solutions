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
ll N, Q, a[MM], opt, l, r, bit1[MM], bit2[MM];
void upd1(int x, int val) {
    for(x; x < MM; x+=x&-x) bit1[x] += val;
}
ll gett1(int x) {
    ll res = 0;
    for(x; x > 0; x-=x&-x) res += bit1[x];
    return res;
}
void upd2(int x, int val) {
    for(x; x < MM; x+=x&-x) bit2[x]+=val;
}
ll gett2(int x) {
    ll res = 0;
    for(x; x > 0; x-=x&-x) res += bit2[x];
    return res;
}
int main()
{
    boost(); 
    cin>>N>>Q;
    for(int i = 1; i <= N; ++i) {
        cin>>a[i];
        if(i%2==0) upd1(i, a[i]);
        else upd2(i, a[i]);
    }
    while(Q--) {
        cin>>opt>>l>>r;
        if(opt == 1) {
            if(l%2==0) upd1(l, r - a[l]);
            else upd2(l, r - a[l]);
            a[l] = r;
        }
        else {
            if(l%2 == 0) {
                cout<<gett1(r) - gett1(l-1)<<endl;
            }
            else cout<<gett2(r) - gett2(l-1)<<endl;
        }
    }
    return 0;
}