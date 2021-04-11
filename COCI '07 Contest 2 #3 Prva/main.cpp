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
const ll MAXN = 25;
using namespace std;
int r, c;
char mat[MAXN][MAXN];
string s  = "zzzzzzzzzzzzzzzzzzzzz", minstr = "";
void solve(){

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(mat[i][j]=='#'){
                if(minstr.length()>=2) s = min(s, minstr);
                minstr = "";
            }
            else minstr += mat[i][j];
        }
        if(minstr.length()>=2){
            if(minstr.length()>=2) s = min(s, minstr);
        }
        minstr = "";
    }
    for(int i = 0; i < c; ++i){
        for(int j = 0; j < r; ++j){
            if(mat[j][i]=='#'){
                if(minstr.length()>=2) s = min(s, minstr);
                minstr = "";
            }
            else minstr += mat[j][i];
        }
        if(minstr.length()>=2) s = min(s, minstr);
        minstr = "";
    }
}
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>r>>c;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin>>mat[i][j];
        }
    }
    solve();
    cout<<s<<endl;
    return 0;
}
