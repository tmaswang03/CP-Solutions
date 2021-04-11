#include <iostream>
#include <stack>
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

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
  int t; gc(t);
  for(int i = 0 ; i < t; ++i){
    stack<int>s;
    int N; gc(N);
    int a = 0;
    stack<int>q;
    for(int i = 0 ; i < N; ++i){
     int j; gc(j);
      q.push(j);
    }
    for(int i = 0 ; i < N; ++i){
      s.push(q.top());
      q.pop();
      while(!s.empty() && s.top()==a+1){
        ++a;
        s.pop();
      }
    }
    if(!s.empty()){
      cout<<"N"<<endl;
    }
    else{
      cout<<"Y"<<endl;
    }
  }
  return 0;
}
