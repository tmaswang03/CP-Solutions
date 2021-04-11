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
ll N, M, K;
// y = max( (N-G)/x, M);
// if N-G/x < M; N-G < MX;
// find when N-G > M*X, let this value be t
// the amount of milk after K days is
// sum (N-G/x)+(K-T)*M;
// binary search for x
// N/X, (N-X)/x, (N-(N-X)/X)/X;

int main()
{
    cin>>N>>M>>K;

    return 0;
}
