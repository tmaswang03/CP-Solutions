#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e2;
using namespace std;
int t, a, b, cur, dst[MM];
vector<int> v[MM];
queue<int>q;
int main()
{
    scanf("%d\n", &t);
    for(int i = 1; i <= 8; ++i){
        for(int j = 1; j <= 3; ++j){
            v[i*10+j].pb(i*10+j+1);
        }v[i*10+4].pb((i+1)*10+1);
    }
    v[12].pb(41); v[42].pb(81);
    while(t--){
        ms(dst, 0x3f3f);
        scanf("%d-%d", &a, &b); cur = 10*a+b;
        dst[cur] = 0;
        q.push(cur);
        while(!q.empty()){
            auto c = q.front(); q.pop();
            for(auto && i : v[c]){
                if(dst[c]+1 < dst[i]){
                    dst[i] = dst[c]+1;
                    q.push(i);
                }
            }
        }
        printf("%d\n", dst[84]+1);
    }
    return 0;
}
