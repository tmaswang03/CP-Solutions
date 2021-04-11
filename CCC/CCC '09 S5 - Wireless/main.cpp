#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <unordered_map>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

void gc(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}



int diffarr[30001][1001];
int main() {
  memset(diffarr,0,sizeof(diffarr));
  int M,N,K; gc(M);gc(N);gc(K);
  for(int i = 0; i <K; ++i){
    int x,y,ra,b;
    gc(x);gc(y);gc(ra);gc(b);
    x--;
    y--;
    int x1,y1;
    int ra2=ra*ra;
    for(int c = max(0,x-ra); c <= min(N-1,x+ra); ++c){
      int tempy=x-c;
      int L = max(0,y-(int)(pow(ra*ra-tempy*tempy,0.5)));
      int R = min(M-1,y+(int)(pow(ra*ra-tempy*tempy,0.5)));
      diffarr[L][c] +=b;
      diffarr[R+1][c]-=b;
    }
  }
  unordered_map<int,int> umap;
  int maxcount = 0;
  int count=0;
  for(int c = 0; c < M; ++c){
    for(int r = 0; r < N; ++r){
      if(c-1>=0){
        diffarr[c][r]+=diffarr[c-1][r];
      }
      if (diffarr[c][r] > maxcount) {
          maxcount = diffarr[c][r];
      }
      umap[diffarr[c][r]]++;
	  }
  }
  printf("%i\n",maxcount);
   printf("%i\n",umap[maxcount]);

  return 0;
}
