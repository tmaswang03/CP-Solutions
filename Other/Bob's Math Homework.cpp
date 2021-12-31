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
using namespace std;
ll N, res = 1;
// i + i + 1 + i + 2 ... i + k - 1 = N
// 2N = k(2i + k - 1)
// k = number of numbers, i is first number
// basically you just find number of numbers that multiply to 2N ??
// also make sure parity of multiple is opposite
// find the number of odd divisors of 2*N
// k*(3k-1) ?
int main()
{
    cin>>N; N*=2;
    for(ll i = 2; i * i <= N; ++i) {
        if(N % i == 0) {
            ll p = 1;
            while(N % i == 0) {
                N /= i; ++p;
            }
            if(i % 2 == 1) res *= p;
        }
    }
    if(N != 1 && N % 2 == 1) res *= 2;
    cout<<res<<endl;
    return 0;
}