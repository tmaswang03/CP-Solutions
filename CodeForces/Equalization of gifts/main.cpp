#include<bits/stdc++.h>
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
const ll MAXN = 50, inf = 0x3f3f3f3f;
using namespace std;
struct gifts{
    ll a, b;
};

bool comp1(const gifts &as, const gifts &bs){
    return (mp(as.a, as.b)<mp(bs.a,bs.b));
}
bool comp2(const gifts &as, const gifts &bs){
    return (mp(as.b, as.a)<mp(bs.b,bs.a));
}
int main()
{
    int t; scan(t);
    for(int i = 0; i < t; ++i){
        ll N, moves = 0; gifts avg {inf, inf}; scan(N);
        gifts arr[N+1];
        for(int j = 0; j < N; ++j){
            scan(arr[j].a); avg.a = min(arr[j].a, avg.a);
        }
        for(int j = 0; j < N; ++j){
            scan(arr[j].b); avg.b = min(arr[j].b, avg.b);
        }
        for(int j = 0; j < N; ++j){
            ll bdiff = arr[j].b - avg.b, adiff = arr[j].a - avg.a, temp1 = min(adiff, bdiff);
            moves += temp1; bdiff-=temp1, adiff -= temp1;
            moves += bdiff+adiff;
        }
        cout<<moves<<endl;
    }
    return 0;
}
