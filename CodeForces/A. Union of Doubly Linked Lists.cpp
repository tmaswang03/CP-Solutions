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
const ll MM = 1e2+10;
using namespace std;
struct lnk{int l, r;};
lnk a[MM]; int N, cur;
int main()
{
    cin>>N;
    for(int i = 1; i <= N; ++i){
        cin<<a[i].l<<a[i].r;
    }
    for(int i = 1; i <= N; ++i){
        if(a[i].l == 0){
            cur = i; cout<<i<<" ";
            for(; cur.r!=0)
        }
    }
    return 0;
}
