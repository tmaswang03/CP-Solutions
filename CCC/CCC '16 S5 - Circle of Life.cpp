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
const ll MM = 1e5+10;
using namespace std;
ll N, T; bool a[MM], p[MM]; char c;
ll mod(ll x) { return ((x%N) + N) %N; }


//1 a[k][i] = a[k-1][i-1]^a[k-1][i+1]

//2 a[k][i] = a[k-2][i-2]^a[k-2][i+2]

//3 a[k][i] = a[k-3][i-3]^a[k-3][i-1]^a[k-3][i+1]^a[k-3][i+3]

//4 a[k][i] = a[k-4][i-4]^a[k-4][i+4]

//5 a[k][i] = a[k-5][i-5]^a[k-5][i-3]^a[k-5][i+3]^a[k-5][i+5]

//6 a[k][i] = a[k-6][i-6]^a[k-6][i-2]^a[k-6][i+2]^a[k-6][i+6]

// a[k][i] = a[k-n][i-n]^a[k-n][i+n]

// use powers of 2 to increment
int main()
{
    boost();
    cin>>N>>T;
    for(int i = 0; i < N; ++i) {
        cin>>c; p[i] = c - '0'; a[i] = p[i];
    }
    for(ll i = 1; i <= T; i<<=1) {
        if(T&i) {
            for(int j = 0; j < N; ++j) {
                a[j] = p[mod(j-i)]^p[mod(j+i)];
            }
            for(int j = 0; j < N; ++j) p[j] = a[j];
        }
    }

    for(int i = 0; i < N; ++i) {
        cout<<a[i];
    }
    return 0;
}