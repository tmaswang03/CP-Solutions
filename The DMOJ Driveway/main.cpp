#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
int main()
{
    int T, M; scan(T); scan(M);
    deque<string> d;
    for(int i = 0; i < T; ++i){
        string s, com; cin>>s>>com;
        if(com == "in"){
            d.pb(s);
        }
        else{
            if(d.back()==s) d.pop_back();
            else if(d.front()==s && M){
                d.pop_front();
                --M;
            }
        }
    }
    for(int i = 0; i < d.size(); ++i){
        cout<<d[i]<<endl;
    }
    return 0;
}
