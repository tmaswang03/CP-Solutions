#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e6+1;
using namespace std;
const ll mod = 1e9+7;
char _;

int main()
{
    ll N,K,R, counter = 0, tempcounter  = 0, p2 = 0; scan(N); scan(K); scan(R);
    bool cams[N+2]; ms(cams, 0);
    p2 = R;
    for(int i = 0; i < K; ++i){
        int n; scan(n); cams[n] = 1;
    }
    stack<int>s;
    for(int i =1; i <= N; ++i){
        tempcounter += cams[i];
        if(!cams[i]){
            s.push(i);
        }
        if(i>=R){
            tempcounter -= cams[i-R];
            while(tempcounter < 2){
                cams[s.top()]=1; s.pop(); ++counter; ++tempcounter;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}
