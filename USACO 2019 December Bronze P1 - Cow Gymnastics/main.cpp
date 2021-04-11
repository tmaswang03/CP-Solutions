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
const ll MN = 25, MM = 35;
using namespace std;
int a[MM][MN], N, K, cur, cnt = 0;
bool valid(int i, int j){
    for(int k = 0; k < K; ++k){
        if(a[k][i]>a[k][j]) return 0;
    }
    return 1;
}
int main()
{
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    cin>>K>>N;
    for(int i = 0; i < K; ++i){
        for(int j = 0; j < N; ++j){
            cin>>cur; a[i][cur] = j;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i==j) continue;
            cnt+=valid(i, j);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
