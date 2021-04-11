#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const int MAXN = 401;
using namespace std;
int pfsum[MAXN][MAXN];

int getsum(int row, int l, int r){
    return pfsum[row][r]-pfsum[row][l-1];
}
int main()
{
    int R,C; scan(R); scan(C);
    for(int r = 0; r < R; ++r){
        for(int c = 0; c < C; ++c){
            char s; cin>>s;
            if(s=='X'){
                pfsum[r][c]=pfsum[r][c-1]+1;
            }
            else{
                pfsum[r][c]=pfsum[r][c-1];
            }
        }
    }
    int res = 0;
    for(int l = 0; l < C; ++l){
        for(int r = l; r < C; ++r){
            int r1 = 0, max1 = 0, tempmax = 0;
            while(r1 < R){
                if(getsum(r1,l,r)==0){
                    ++tempmax;
                }
                else{
                    max1 = max(max1, tempmax);
                    tempmax=0;
                }
                ++r1;
            }
            max1 = max(max1, tempmax);
            if(max1!=0) res = max(res,2*(r-l+1)+2*max1);
//            cout<<l<<" "<<r<<" "<<max1<<" "<<res<<endl;
        }
    }
    cout<<res-1<<endl;
    return 0;
}
