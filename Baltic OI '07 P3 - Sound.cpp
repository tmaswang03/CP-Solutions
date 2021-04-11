#include<bits/stdc++.h>
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
const int MAXN = 1e6+10;
int a[MAXN];
using namespace std;
int main()
{
    int n, m, c, l = 1; scan(n); scan(m); scan(c);
    bool istrue = 0;
    deque<pair<int, int > >mindq, maxdq;
    for(int i = 0 ; i < n; ++i){
        int t; scan(t);
        while(!maxdq.empty() && maxdq.front().s<i-m+1) maxdq.pop_front();
        while(!mindq.empty() && mindq.front().s<i-m+1) mindq.pop_front();
        while(!mindq.empty() && mindq.back().f>= t) mindq.pop_back();
        while(!maxdq.empty() && maxdq.back().f<= t) maxdq.pop_back();
        mindq.pb({t, i}); maxdq.pb({t, i});
        if(i>= m-1 && maxdq.front().f-mindq.front().f<=c){
            printf("%lld\n", i-m+2);
            istrue = 1;
        }
    }
    if(!istrue){
        printf("NONE\n");
    }
    return 0;
}
