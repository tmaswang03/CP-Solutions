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
using namespace std;

int main() {
  int n,arr[1000000]; scan(n);
  for(int i = 0 ; i < n; i++)
    scan(arr[i]);

  int prefixsum[1000000];
  prefixsum[0]=arr[0];
  for(int i = 1; i < n; i++){
    prefixsum[i]=prefixsum[i-1]+arr[i];
  }
  int q; scan(q);
  for(int i = 0 ; i < q; i++){
    int a,b; scan(a);scan(b);
    if(a==0){
      cout<<prefixsum[b]<<endl;
    }
    else{
      cout<<prefixsum[b]-prefixsum[a-1]<<endl;
    }
  }
  return 0;
}
