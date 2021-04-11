#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
#define boost() cin.tie(0); cin.sync_with_stdio(0);
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
const ll MM = 2e5+1, inf = 0x3f3f3f3f;
using namespace std;
vector <int> v[MM];
int main()
{
    boost();
    int t; cin>>t;
    while(t--){
        int len, segs = 0, place[MM]; string s; cin>>len>>s;
        queue<int> q[2];
        for(int i = 0; i < len; ++i){
            bool cur = s[i]-'0';
            if(q[!cur].empty()){
                ++segs;
                q[cur].push(segs);
                place[i] = segs;
            }
            else{
                place[i] = q[!cur].front(); q[!cur].pop();
                q[cur].push(place[i]);
            }
        }
        printf("%lld\n", segs);
        for(int i = 0; i < len; ++i){
            printf("%lld ",  place[i]);
        }printf("\n");
    }
    return 0;
}
