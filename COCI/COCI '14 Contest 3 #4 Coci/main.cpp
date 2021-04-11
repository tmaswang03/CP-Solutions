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
const ll MAX1 = 652;
const ll MAXN = 500001;
#define INF 0x3f3f3f3f
using namespace std;

int arr1[MAXN], arr2[MAXN], psa[MAX1][MAX1], arr[MAX1][MAX1];

int main() {
    int N; scan(N);
    for (int i=0; i<N; i++) {
      scan(arr1[i]); scan(arr2[i]);
      ++arr[arr1[i]][arr2[i]];
      ++psa[arr1[i]][arr2[i]];
    }
    for (int i=0; i<=650; i++) {
      for (int j=0; j<=650; j++) {
        psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
      }
    }

      for(int i = 0; i < N; ++i){
        int temp1 = arr1[i], temp2 = arr2[i];
        int res1 =psa[650][650]-psa[temp1][650]-psa[650][temp2]+psa[temp1][temp2]+1;
        int res2 =  psa[650][650]-psa[temp1-1][temp2-1];
        if(temp1==650) res2-=arr[0][temp2];
        if(temp2==650) res2-=arr[temp1][0];
        printf("%d %d\n",res1,res2);
    }

    return 0;
}
