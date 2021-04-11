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
int N, a[MM], h[MM];
int main()
{
    // tell you how many in front
    // order of tosses matter
    // choices : you can land in same hole, in front or behind
    // if there are 0 in front you can either be tied first or first
    // if there are x in front you can either be tied xth place or xth
    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>a[i];
    for(int i = 1; i <= N; ++i){
        // there are i-1 javelins tossed
        // if there are k holes in front there are some range of 0 to i-1-k behind you
        // the rest are tossed together
        //
        for(int j = 1; j < i; ++j){

        }
    }
    return 0;
}
