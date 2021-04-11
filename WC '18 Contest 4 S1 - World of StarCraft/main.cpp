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
const ll MM = 1e5+10;
using namespace std;
char c; int typ[MM], N, M, K, a, b, res, head[MM], rnk[MM]; vector<int> v[MM];
int find_par(int x){
    if(head[x]==x) return x;
    return head[x] = find_par(head[x]);
}
void join(int a, int b){
    a = find_par(a); b = find_par(b);
    if(rnk[a]<rnk[b]) swap(a, b);
    head[b] = a; rnk[a]+=rnk[b];
}
int main()
{
    cin>>N>>M>>K;
    for(int i = 1; i <= N; ++i){
        cin>>c;
        if(c=='T') typ[i] = 1;
        else if (c=='Z') typ[i] = 2;
        head[i] = i;
    }
    for(int i = 0; i < M; ++i){
        cin>>a>>b;
        if(typ[a]==typ[b]&&find_par(a)!=find_par(b)) join(a, b);
    }
    while(K--){
        cin>>a>>b;
        if(find_par(a)==find_par(b)) ++res;
    }
    cout<<res<<endl;
    return 0;
}
