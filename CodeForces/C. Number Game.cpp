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
ll N, t, cnt = 0;
// subtract 1 from N or divide N by odd if it's odd
// idea : try to make the number even at all times
// if number is odd, divide by itself
// if it's even, find divisor that divided makes it even
// find, greatest odd divisor and divide by that,
ll get(ll N){
    ll cur = 2;
    while(N%cur==0){
        cur<<=1;
    }
    cur>>=1;
    return cur;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>N;
        if(N==1){
            cout<<"FastestFinger"<<endl;
        }
        else if(N%2==1){
            cout<<"Ashishgup"<<endl; // just divide by itself
        }
        else{
            N = get(N);
            // if you just subtract then N becomes odd and other person wins by dividing by itself
            //
            if(N)
        }
    }
    return 0;
}
