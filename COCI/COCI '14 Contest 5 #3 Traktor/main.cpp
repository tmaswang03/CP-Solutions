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
const ll MM = 1e5+10;
using namespace std;
int rs[MM], col[MM], d1[2*MM], d2[2*MM], N, K, x, y;
pii x[i], y[i];
bool check(){
    for(int i = 0; i < MM; ++i){
        if(rs[i]>=K||col[i]>=K) return 1;
    }
    for(int i = 0; i < 2*MM; ++i){
        if(d1[i]>=K || d2[i]>=K) return 1;
    }
    return 0;
}
int main()
{
    cin>>N>>K;
    for(int i = 0; i < N; ++i){
        cin>>x>>y;
        ++rs[x]; ++col[y]; ++d1[x+y]; ++d2[100000-x+1+y];
        if(check()){cout<<i+1<<endl; return 0;};
    }
    cout<<-1<<endl;
    return 0;
}
