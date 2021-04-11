#include<bits/stdc++.h>
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
const ll MAXN = 50;
using namespace std;
vector<int> v;
int main()
{
    int t; scan(t);
    for(int i = 0; i < t; ++i){
        v.clear(); int N, l = 0; scan(N); bool istrue = false;
        for(int j = 0; j < N; ++j){
            int a; scan(a); v.pb(a);
        }
        sort(v.begin(), v.end());
        while(l < v.size()){
            if(l+1 < v.size() && v[l+1]-v[l]<= 1) v.erase(v.begin()+l);
            else ++l;
        }
        if(v.size()<=1) istrue = 1;
        printf(istrue ? "YES\n" : "NO\n");
    }
    return 0;
}
