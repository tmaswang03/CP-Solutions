#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e6+10;
using namespace std;
int N, dp[MM], a[MM],  mn[MM],  res = 0;
// idea from: https://www.youtube.com/watch?v=S9oUiVYEq7E
// array holds minimum last value for a subsequence length n
// binary search for smallest array value and compare to see if the next value
// i'm homeless wtf
int main()
{
    scan(N);
    scan(a[0]); mn[0] =  a[0];
    for(int i = 1; i < N; ++i){
        scan(a[i]);
        if(a[i]>mn[res]){
            ++res; mn[res] = a[i];
        }
        else{
            int ind = upper_bound(mn, mn+res+1, a[i]) - mn;
            mn[ind] = a[i];
        }
    }
    printf("%d\n", res+1);
    return 0;
}
