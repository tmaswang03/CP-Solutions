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
int N, Q, bit[MM][MM], tx, ty, bx, by, val; char opt;
void upd(int x, int y, int val){
    for(int i = x; i > 0; i-=i&-i){
        for(int j = y; j > 0; j-=j&-j) bit[i][j]+=val;
    }
}
int flip(int in){
    return 5e3 - in;
}
int main()
{
    cin>>N>>Q;
    while(Q--){
        cin>>opt>>tx>>ty>>bx>>by; ++tx; ++ty; ++bx; ++by;
        if(opt=='U'){
            cin>>val;
            upd(bx, by, val);
            upd(bx, ty-1, -val);
            upd(tx-1, by, -val);
            upd(tx-1, ty-1, val);
        }
        else{
            int res = 0;
            for(int i = tx; i <= bx; ++i){
                for(int j = ty; j <= by; ++j) res+=query(i, j);
            }
            cout<<res<<endl;
        }
    }

    return 0;
}
