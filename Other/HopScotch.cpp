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
const ll MM = 2e5+10;
using namespace std;
ll N, rt, a[MM], jmp[MM], nxt[MM], blok[MM], Q, opt, x, y;
void build(){
    for(int i = 0; i < N; ++i) blok[i] = i/rt;
    for(int i = N-1; i >= 0;--i){
        if(i+a[i]>=min(rt*(blok[i]+1), N)){
            jmp[i] = 1; nxt[i] = a[i]+i;
        }
        else{
            jmp[i] = jmp[i+a[i]]+1, nxt[i] = nxt[i+a[i]];
        }
    }
}
void upd(int x, int j){
    a[x]=j;
    if(x+j>=min(rt*(blok[x]+1), N)){
        jmp[x] = 1; nxt[x] = j+x;
    }
    else{
        jmp[x] = jmp[x+j]+1; nxt[x] = nxt[x+j];
    }
    for(int i = x-1; i>=0 && blok[i]==blok[x]; --i){
        if(i+a[i]>=min(rt*(blok[i]+1), N)){
            jmp[i] = 1; nxt[i] = a[i]+i;
        }
        else{
            jmp[i] = jmp[i+a[i]]+1, nxt[i] = nxt[i+a[i]];
        }
    }
}
int main()
{
    boost();
    cin>>N; rt = sqrt(N);
    for(int i = 0; i < N; ++i) cin>>a[i];
    build();
    cin>>Q;
    while(Q--){
        cin>>opt>>x;
        if(opt==1){
            int cnt = 0;
            for(int cur = x; cur < N; cur=nxt[cur]) cnt+=jmp[cur];
            cout<<cnt<<endl;
        }
        else{
            cin>>y; upd(x, y);
        }
    }
    return 0;
}
