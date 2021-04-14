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
const ll MM = 1e5+10;
using namespace std;
pii a[MM]; int N, cnt;
bool cmp(pii x, pii y){
    return abs(x.f)+abs(x.s) < abs(y.f) + abs(y.s);
}
int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d%d", &a[i].f, &a[i].s);
    sort(a, a+N, cmp); cnt = 2*N;
    for(int i = 0; i < N; ++i){
       if(a[i].f!=0) cnt+=2;
       if(a[i].s!=0) cnt+=2;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < N; ++i){
        if(a[i].f < 0) printf("1 %d L\n", abs(a[i].f));
        else if(a[i].f > 0) printf("1 %d R\n", abs(a[i].f));
        if(a[i].s < 0) printf("1 %d D\n", abs(a[i].s));
        else if(a[i].s > 0) printf("1 %d U\n", abs(a[i].s));
        cout<<2<<endl;
        if(a[i].f > 0) printf("1 %d L\n", abs(a[i].f));
        else if(a[i].f < 0) printf("1 %d R\n", abs(a[i].f));
        if(a[i].s > 0) printf("1 %d D\n", abs(a[i].s));
        else if(a[i].s < 0) printf("1 %d U\n", abs(a[i].s));
        cout<<3<<endl;
    }
    return 0;
}
