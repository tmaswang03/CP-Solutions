#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int t, x1, x2, y1, y2, z1, z2, res, tmi;
int main()
{
    cin>>t;
    while(t--){
        res = 0;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        // 0, 1, 2, 0, 1, 2
        // make as many 2 1 and least 1 2 as possible
        tmi = min(z1, y2); // max 2, 1
        res += 2*tmi;
        z1-= tmi; y2-=tmi;
        tmi = min(y1, y2); // max 1, 1
        y1 -= tmi; y2 -= tmi;
        tmi = min(y1, x2); // max 1, 0
        y1-=tmi; x2-=tmi;
        tmi = min(x1, z2); // max 0, 2
        x1-=tmi; z2-=tmi;
        tmi = min(y1, z2); // max 1, 2
        res-= 2*tmi;
        cout<<res<<endl;
    }

    return 0;
}
