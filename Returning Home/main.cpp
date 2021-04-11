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
const ll MN = 5e3+10, MM = 5e5+10;
using namespace std;
int N, M, l, r, len, cnt; string tmp, s[MN]; vector<int> st[40][40]; bool mark[MN];
int main()
{
    cin>>N>>M>>len; cnt = N;
    for(int i = 0; i < N; ++i){
        cin>>s[i];
    }
    for(int l = 0; l < len; ++l){
        for(int r = l; r < len; ++r){
            for(int k = 0; k < N; ++k){
                string a = (s[k]).substr(l, r-l+1);
                string b = a; reverse(b.begin(), b.end());
                if(a!=b) st[l+1][r+1].pb(k);
            }
        }
    }
    while(M--){
        cin>>l>>r;
        for(auto && i : st[l][r]){
            if(!mark[i]){
                --cnt; mark[i] = 1;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
