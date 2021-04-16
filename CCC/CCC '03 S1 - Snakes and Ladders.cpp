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
using namespace std;
int x, cur = 1;
int main()
{
    while(1){
        scan(x);
        if(cur+x<=100) cur+=x;
        if(x==0){ printf("You Quit!\n"); return 0; }
        if(cur==54) cur = 19;
        else if(cur==90) cur = 48;
        else if(cur==99) cur = 77;
        else if(cur==9) cur = 34;
        else if(cur==40) cur = 64;
        else if(cur==67) cur = 86;
        printf("You are now on square %d\n", min(cur, 100));
        if(cur==100){ printf("You Win!\n"); return 0; }
    }
}
