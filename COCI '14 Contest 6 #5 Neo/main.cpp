#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
char _;
const ll MAXN = 1e3+20;
int matrix[MAXN][MAXN], temparr[MAXN];
bool arr[MAXN][MAXN];
int main()
{
    cin.tie(0); cin.sync_with_stdio(0); ms(arr, 0);
    int R, S, res = 0; cin>>R>>S;
    for(int r = 0; r< R; ++r){
        for(int c = 0; c < S; ++c){
            cin>>matrix[r][c];
        }
    }
    for(int r = 0; r < R-1; ++r){
        for(int c = 0; c < S-1; ++c){
            if(matrix[r][c]+matrix[r+1][c+1]<= matrix[r+1][c]+matrix[r][c+1]) arr[r][c] = 1;
        }
    }
    for(int r = 0; r < R; ++r){
        for(int c = 0; c < S; ++c){
            if(arr[r][c]) ++temparr[c];
            else temparr[c] = 0;
        }
        temparr[S] = -1;
        stack<int>s;
        int i = 0;
        while(i < S){
            if(s.empty()|| temparr[s.top()]<=temparr[i]) s.push(i++);
            else{
                int temp1 = s.top(); s.pop();
                if(s.empty()) res = max(res, (temparr[temp1]+1) * (i+1) );
                else res = max(res, (temparr[temp1]+1) * (i - s.top()));
            }
        }
        while(!s.empty()){
            int temp1 = s.top(); s.pop();
            if(s.empty()) res = max(res, (temparr[temp1]+1) * (i+1));
            else res = max(res, (temparr[temp1]+1) * (i - s.top()));
        }
    }
    cout<<res<<endl;
    return 0;
}
