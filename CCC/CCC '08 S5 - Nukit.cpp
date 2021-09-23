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
int T, a[4], tmp[4], m[5][4] = { {2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1} }, dp[35][35][35][35];
bool check() {
    for(int i = 0; i < 5; ++i) {
        bool pass = 1;
        for(int j = 0; j < 4; ++j) {
            if(m[i][j] > tmp[j]) pass = 0;
        }
        if(pass) return 1;
    }
    return 0;
}
bool dfs(int A, int B, int C, int D) {
//    cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    if(A < 0 || B < 0 || C < 0 || D < 0) return 1;
    if(dp[A][B][C][D] != -1) return dp[A][B][C][D];
    tmp[0] = A; tmp[1] = B; tmp[2] = C; tmp[3] = D;
    if(!check()) {
        dp[A][B][C][D] = 0; return 0;
    }
    bool solve = 0;
    for(int i = 0; i < 5; ++i) {
        if(!dfs(A - m[i][0], B - m[i][1], C - m[i][2], D - m[i][3])) solve = 1;
    }
    return dp[A][B][C][D] = solve;
}
int main()
{
    cin>>T; ms(dp, -1);
    while(T--) {
        for(int i = 0; i < 4; ++i) cin>>a[i];
        if(dfs(a[0], a[1], a[2], a[3])){
            cout<<"Patrick"<<endl;
        }
        else cout<<"Roland"<<endl;
    }
    return 0;
}