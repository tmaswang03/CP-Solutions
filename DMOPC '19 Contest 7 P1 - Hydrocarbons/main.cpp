#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;


int main() {
  int A,B,C,D; gc(A); gc(B); gc(C); gc(D);
  int Carbons = 1+A+B+C;
  int bonds = D+6*C+4*B+2*A;

  if(bonds==4*Carbons){
    printf("C%iH%i\n",Carbons,D);
  }
  else{
    printf("invalid\n");
  }


  return 0;
}
