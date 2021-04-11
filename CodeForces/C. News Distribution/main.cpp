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
const ll MM =5e5+10;
using namespace std;
int N, M, rank1[MM], head[MM], k,  u, h;
int getpar(int a){
    if(head[a]==a) return a;
    return head[a] = getpar(head[a]);
}

void combine(int a, int b){
    a = getpar(a); b= getpar(b);
    if(head[a]==head[b]) return;
    if(rank1[a]<rank1[b]) swap(a, b);
    rank1[a]+=rank1[b];
    head[b] = a;
}

int main()
{
    scan(N); scan(M);
    iota(head, head+N+1, 0);
    for(int i = 1; i <= N; ++i) rank1[i] = 1;
    for(int i = 0; i < M;  ++i){
        scan(k);
        if(k) scan(h);
        for(int i = 0; i < k-1; ++i){
            scan(u); combine(h, u);
        }
    }
    for(int i = 1; i <= N; ++i){
        printf("%d\n", rank1[getpar(i)]);
    }
    return 0;
}
