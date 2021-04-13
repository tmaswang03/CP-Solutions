#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
using namespace std;

int main()
{
    int N; scan(N);
    for(int i = 0; i < N; ++i){
        ll n,a,b,t; scan(n); scan(a); scan(b); scan(t);
        ll temp1 = ceil((long double)(t+b*n)/(long double)(a+b));
        if(temp1>n){
            cout<<-1<<endl;
        }
        else{
            cout<<temp1<<endl;
        }
    }
    return 0;
}
