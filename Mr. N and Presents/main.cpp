#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const ll MM = 1e6+10;
using namespace std;
int Q;
map<int, int> a;
deque<pair<int, int> >dq;
int main()
{
    scan(Q);
    for(int i = 0; i < Q; ++i){
        char opt; int x;
        scanf("%c", &opt); scan(x);
        if(opt=='F'){
            dq.push_front({x, i});
            a[x] = i;
        }
        else if(opt == 'E'){
            dq.push_back({x, i});
            a[x] = i;
        }
        else{
            a[x] = -1;
        }
    }
    for(int i = 0; i < dq.size(); ++i){
        if(dq[i].s==a[dq[i].f]){
            printf("%d\n", dq[i].f);
        }
    }
    return 0;
}
