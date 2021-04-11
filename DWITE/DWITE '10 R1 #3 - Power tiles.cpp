#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int solve(int a, int b){
    int res = 0;
    if(a%2==1 && b%2==1){
        res+=a+b-1;
        res+=solve(a/2, b/2);
    }
    else if(a%2==1){
        res+=b;
        res+=solve(a/2, b/2);
    }
    else if (b%2==1){
        res+=a;
        res+=solve(a/2, b/2);
    }
    else if(a && b){
        res+=solve(a/2, b/2);
    }
    return res;
}

int main()
{
    for(int t = 0; t < 5; ++t){
        int a, b; scan(a); scan(b);
        cout<<solve(a,b)<<endl;
    }
    return 0;
}
