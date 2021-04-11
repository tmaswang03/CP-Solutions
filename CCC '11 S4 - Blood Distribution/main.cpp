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
// type o -> type o
// type a -> type a or o
// type b -> type b or o
// type ab -> any
// + -> +/-
// - -> -
// o-, o+, a-, a+, b-, b+, ab-, ab+
// 0    1   2   3   4   5  6     7
int a[10], re[10],res;
int main()
{
    for(int i = 0; i < 8; ++i){
        scan(a[i]);
    }
    for(int i = 0; i < 8; ++i){
        scan(re[i]);
    }
    for(int i = 0; i < 8; ++i){
        int tm = a[i], tr = re[i];
        res+= min(tm, tr);
        a[i]-=min(tm, tr); re[i]-=min(tm, tr);
    }
    for(int i = 0; i < 8; ++i){
        if(i%2==0){
            if(re[i]!=0){
                int tm = a[i], tr = re[i+1];
                res+=min(tm, tr);
                re[i+1]-=min(tm, tr);
                a[i]-=min(tm, tr);
            }
        }
    }
    int tl = a[0], tr = re[2], tn = re[4];
    res += min(tl, tr); a[0]-=min(tl, tr); re[2] -= min(tl, tr); tl -= min(tl, tr);
    return 0;
}
