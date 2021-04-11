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
using namespace std;
// moves, y+2, x+1
// y+1, x+2; can enter : X <= xi < X+H, Y<= yi < Y+V
ll X, Y, H, V, T, cx = 0, cy = 0;
int main()
{
    cin>>X>>Y>>H>>V>>T;
    for(int i = 1; i < T; ++i){
        if(cx>=X && cx<X+H && cy>=Y && cy<Y+V) break;
        if(X-cx >= Y-cy && cx+2 < X+H){ cx+=2; ++cy;}
        else if(cy+2 < Y+V) {++cx; cy+=2;}
    }
    if(cx>=X && cx<X+H && cy>=Y && cy<Y+V) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
