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
using namespace std;
ll a, b;
vector<ll> res;
bool ye(ll n){
    if(n<=1) return 0;
    for(ll i = 2; i*i <= n; ++i){
        if(n%i==0) return 0;
    }
    return 1;
}
void prnt(){
    cout<<res.size()<<endl;
    for(auto && i : res){
        cout<<i<<" ";
    }
}
int main()
{
    // key point: difference between 2 numbers must be 2, otherwise number is not prime;
    // cases :
    // a is odd, b is odd, both > 2 prime
    // numbers possible = a+2, a-2, b+2, b-2;
    // numbers: a, a+2, b-2, b,
    // a, a+2, b-2, b, b+2, 2,
    // difference between a = a, a+2,
    // a, b
    // a, 2, b+2, b
    // a, 2, b
    // a, a+2, 2, b
    // a, a+2, b-2, b
    // a, a+2, 2, b-2, b
    // a, a+2, 2, b+2, b
    scan(a); scan(b);
    res.pb(a);
    if(ye(abs(b-a))){
        res.pb(b); prnt(); return 0;
    }
    if(a!=2 && b!=2){
        if(ye(abs(a-2))){
            res.pb(2);
            if(ye(b+2)){
                res.pb(b+2); res.pb(b); prnt(); return 0;
            }
            else if(ye(abs(b-2) )){
                res.pb(b); prnt(); return 0;
            }
        }
        else if(ye(a+2)){
            res.pb(a+2);
            if(ye(b-2)){
                res.pb(2);  res.pb(b); prnt(); return 0;
            }
            else if(b+2){
                res.pb(2); res.pb(b+2); res.pb(b); prnt(); return 0;
            }
        }
    }
    else if(a==2){
        if(ye(b+2)){
            res.pb(b+2); res.pb(b); prnt(); return 0;
        }
    }
    else{
        if(ye(a+2)){
            res.pb(a+2); res.pb(b); prnt(); return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
