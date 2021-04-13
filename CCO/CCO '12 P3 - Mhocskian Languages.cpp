#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
vector<int>chars, terminals; vector<pair< int, int> >v[30];
string str; bool ltou [30][30]; //whether lower case (first index) can change to upper case
int dp[35][35][35]; //stores whether it is possible to represent L, R with character I;
int convertu(char s){
    return int(s-'A');
}
int convertl(char s){
    return int(s-'a');
}

// v2 = upper to 2 upper
int solve(int upper, int l, int r){
    int ret = dp[upper][l][r];
    if(ret!=-1) return ret;
    if(l==r && ltou[convertl(str[l])][upper] == 1) return dp[upper][l][r] = 1;
    for(int p = l; p < r; ++p){
        for(auto && i : v[upper]){
            if(solve(i.first, l, p) && solve(i.second, p+1, r)){
                return dp[upper][l][r] = 1;
            }
        }
    }
    return dp[upper][l][r] = 0;
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0); ms(ltou, 0);
    int V, T, R, W; cin>>V>>T;
    char start; cin>>start;
    for(int i = 1; i < V; ++i){
        char s; cin>>s; chars.pb(convertu(s));
    }
    for(int i = 0; i < T; ++i){
        char s; cin>>s; terminals.pb(convertl(s));
    }
    cin>>R;
    for(int i = 0; i < R; ++i){ // lower to upper
        char s, t; cin>>s>>t;
        ltou[convertl(t)][convertu(s)] = 1;
    }
    cin>>R;
    for(int i = 0; i < R; ++i){//upper to 2 upper
        char s,t, u; cin>>s>>t>>u;
        v[convertu(s)].pb({convertu(t),convertu(u)});
    }
    cin>>W;
    for(int i = 0; i < W; ++i){
        ms(dp, -1);
        cin>>str;
        cout<<solve(convertu(start), 0, str.length()-1)<<endl;
    }
    return 0;
}
