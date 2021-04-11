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
const ll MM = 250, MN = 10;
using namespace std;
int N, K, x[MN], c[MN], cnt; pii a[MM];
bool check(){
    for(int i = 0; i < N; ++i) x[c[i]] = i;
    for(int i  = 0; i < K; ++i){
        if(x[a[i].f] > x[a[i].s]) return 0;
    }
    return 1;
}
int main()
{
    cin>>N>>K;
    iota(c, c+N, 1);
    for(int i = 0; i < K; ++i){
        cin>>a[i].f>>a[i].s;
    }
    do{
      cnt+=check();
    } while (next_permutation(c, c+N));
    cout<<cnt<<endl;
    return 0;
}
