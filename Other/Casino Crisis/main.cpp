#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e3+10;
using namespace std;
int a[MM];
queue<pair<int, int> >q;
int main()
{
    int N, Q, res; scan(N); scan(Q); scan(a[1]);
    for(int i = 2; i <= N; ++i){
        scan(a[i]);
        int it = upper_bound(a, a+i, a[i]) - a;
        if(it^i){
            q.push({it, i-1}); q.push({it, i});
        }
        sort(a, a+i+1);
    }
    printf("%d\n", q.size());
    while(!q.empty()){
        printf("%d %d\n", q.front().f, q.front().s);
        q.pop();
    }
    return 0;
}
