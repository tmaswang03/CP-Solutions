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
    int T; scan(T);
    for(int i = 1; i <= T; ++i){
        int N; scan(N);
        deque<int>dq1, dq2, dq3;
        for(int j = 0; j < N; ++j){
            int a; scan(a);
            dq1.pb(a); dq3.pb(a);
        }
        dq2.pb(dq1.back());
        dq1.pop_back();
        while(!dq1.empty()){
            int f = dq1.front(), b = dq1.back(), f1 = dq2.front(), b1 = dq2.back();
            if(f==f1-1){
                dq2.push_front(f);
                dq1.pop_front();
            }
            else if (f==b1+1){
                dq2.pb(f);
                dq1.pop_front();
            }
            else if (b==b1+1){
                dq2.pb(b);
                dq1.pop_back();
            }
            else if(b == f1-1){
                dq2.push_front(b);
                dq1.pop_back();
            }
            else break;
        } dq2.clear();
        dq2.pb(dq3.front());
        dq3.pop_front();
        while(!dq3.empty()){
            int f = dq3.front(), b = dq3.back(), f1 = dq2.front(), b1 = dq2.back();
            if(f==f1-1){
                dq2.push_front(f);
                dq3.pop_front();
            }
            else if (f==b1+1){
                dq2.pb(f);
                dq3.pop_front();
            }
            else if (b==b1+1){
                dq2.pb(b);
                dq3.pop_back();
            }
            else if(b == f1-1){
                dq2.push_front(b);
                dq3.pop_back();
            }
            else break;
        }
        if(dq1.empty()||dq3.empty()){
            printf("Case #%i: yes\n", i);
        }
        else printf("Case #%i: no\n", i);
    }
    return 0;
}
