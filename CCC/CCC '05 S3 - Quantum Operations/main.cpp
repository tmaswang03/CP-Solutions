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
const ll MM = 1e3+50, inf = 1e9;
using namespace std;
int res[MM][MM], a[MM][MM], tmp[MM][MM], N, R, C, cr, cc, min1 = inf, max1, minr = inf, maxr, minc = inf, maxc;
void mult(){
    for(int i = 0; i < cr; ++i){
        for(int j = 0; j < cc; ++j){
            for(int ni = 0; ni < R; ++ni){
                for(int nj = 0; nj < C; ++nj){
                    tmp[i*R+ni][j*C+nj] =res[i][j]*a[ni][nj];
                }
            }
        }
    }
    cr *= R;
    cc *= C;
    for(int i = 0; i < cr; ++i){
        for(int j = 0; j < cc; ++j){
            res[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>N;
    for(int t = 0; t < N; ++t){
        cin>>R>>C;
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j) cin>>a[i][j];
        }
        if(!t){
            cr = R; cc = C;
            for(int i = 0; i < R; ++i){
                for(int j = 0; j < C; ++j) res[i][j]=a[i][j];
            }
        }
        else mult();
    }
    for(int i = 0; i < cr; ++i){
        int sum = 0;
        for(int j = 0; j < cc; ++j){
            min1 = min(min1, res[i][j]);
            max1 = max(max1, res[i][j]);
            sum+=res[i][j];
        }
        minr = min(minr, sum);
        maxr = max(maxr, sum);
    }
    for(int i = 0; i < cc; ++i){
        int sum = 0;
        for(int j = 0; j < cr; ++j){
            sum+=res[j][i];
        }
        minc = min(minc, sum);
        maxc = max(maxc, sum);
    }
    cout<<cr<<" "<<cc<<endl;
    for(int i = 0; i < cr; ++i){
        for(int j = 0; j < cc; ++j){
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }
    cout<<max1<<"\n"<<min1<<"\n"<<maxr<<"\n"<<minr<<"\n"<<maxc<<"\n"<<minc<<"\n"<<endl;
    return 0;
}
