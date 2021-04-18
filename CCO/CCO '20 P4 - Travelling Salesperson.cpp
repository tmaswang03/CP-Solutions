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
const ll MM = 2e3+10;
using namespace std;
int N; string tmp; bool v[MM][MM]; vector<int> col[2];
int main()
{
    cin>>N;
    for(int i = 1; i < N; ++i){
        cin>>tmp;
        for(int j = 0; j < i; ++j){
            if(tmp[j]=='R'){
                v[i][j]=1; v[j][i]=1;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        col[0].clear(); col[1].clear();
        col[0].pb((i+2)%N); col[1].pb((i+1)%N);
        for(int j = 3; j <= N; ++j){
            int cur = (i+j)%N;
            if(col[0].empty()||v[col[0].back()][cur]==0) col[0].pb(cur);
            else if(col[1].empty()||v[col[1].back()][cur]==1) col[1].pb(cur);
            else{
                int b0 = col[0].back(), b1 = col[1].back();
                if(v[b0][b1]==1){
                    col[0].pop_back(); col[1].pb(b0);
                }
                else{
                    col[1].pop_back(); col[0].pb(b1);
                }
                --j;
            }
        }
        cout<<N<<endl;
        reverse(col[0].begin(), col[0].end()); reverse(col[1].begin(), col[1].end());
        if(col[1][0]==i){
            for(auto && it : col[1]) cout<<it+1<<" ";
            for(auto && it : col[0]) cout<<it+1<<" ";
        }
        else{
            for(auto && it : col[0]) cout<<it+1<<" ";
            for(auto && it : col[1]) cout<<it+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}